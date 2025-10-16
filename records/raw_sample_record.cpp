#include <fstream>
#include <iostream> 
#include <vector>
#include <complex>
#include <string>
#include <memory>
#include <algorithm>

#include "raw_sample_record.h" 
#include "../misc/common.h"

// Constructor
RawSampleRecord::RawSampleRecord( std::string path, SampFormat format, BitDepth bits, double fs, double tofs__sse, double tofs_frac__ps) : Record() {
   // Initialize member variables
   _file_path = path;
   sample_format = format;
   bits_per_sample = bits;
   num_samples = 0;
   sample_rate__Hz = fs;
   time_of_first_sample__sse = tofs__sse;
   time_of_first_sample_frac__ps = tofs_frac__ps;

   // Open the binary file for reading
   std::ifstream input_file( path, std::ios::binary);
 
   // Check if the file was opened successfully
   if (!input_file.is_open()) {
       std::cerr << "Error opening file: " << _file_path << std::endl;
   }
   
   // Determine the size of the file to allocate memory for reading
   input_file.seekg(0, std::ios::end); // Move to the end of the file
   uint32_t file_size = input_file.tellg(); // Get the current position (file size)
   input_file.seekg(0, std::ios::beg); // Move back to the beginning of the file
 
   // Calculate the number of doubles in the file
   // Handle potential partial doubles at the end of the file if necessary
   num_samples = file_size / sizeof(double);

   // Close the file
   input_file.close();
}

// Public Functions
std::string RawSampleRecord::get_path() { return _file_path; }
std::shared_ptr<std::complex<double>[]> RawSampleRecord::get_samples() { return _samples; }

void RawSampleRecord::set_sample_format( SampFormat f ) { sample_format = f; }
void RawSampleRecord::set_bits_per_sample( BitDepth bits ) { bits_per_sample = bits; }
void RawSampleRecord::set_sample_rate__Hz( double fs ) { sample_rate__Hz = fs; }
void RawSampleRecord::set_time_of_first_sample__sse( double tofs__sse ) { time_of_first_sample__sse = tofs__sse; }
void RawSampleRecord::set_time_of_first_sample_frac__ps( double tofs_frac__ps ) { time_of_first_sample_frac__ps = tofs_frac__ps; }


/**
* @brief Reads the samples embedded in the record
 *
 * This function reads the raw samples only from the record.
 *
 * @return Status code indicating success (1), or failure (other than 1)
 */
int RawSampleRecord::read_samples() {
   int status = 0;
 
   // Open the binary file for reading
   std::ifstream input_file( _file_path, std::ios::binary);
 
   // Check if the file was opened successfully
   if (!input_file.is_open()) {
       std::cerr << "Error opening file: " << _file_path << std::endl;
   }
   
   // Determine the size of the file to allocate memory for reading
   input_file.seekg(0, std::ios::end); // Move to the end of the file
   uint32_t file_size = input_file.tellg(); // Get the current position (file size)
   input_file.seekg(0, std::ios::beg); // Move back to the beginning of the file
 
   // Calculate the number of doubles in the file
   // Handle potential partial doubles at the end of the file if necessary
   uint32_t num_chunks = file_size / sizeof(double);
 
   // Create a vector to store the doubles
   std::vector<double> data(num_chunks);
  
   // Read the binary data into the vector
   // reinterpret_cast is used to treat the memory address of the vector's data
   // as a char* for the read function, which expects a char* buffer.
   input_file.read(reinterpret_cast<char*>(data.data()), num_chunks * sizeof(double));
 
   // Check if the read operation was successful
   if (!input_file) {
       std::cerr << "Error reading data from file: " << _file_path << std::endl;
   }
 
   // Create a pointer to complex doubles that is half the size of the data read
   _samples = std::shared_ptr<std::complex<double>[]>(new std::complex<double>[num_chunks/2]);
 
   // Iterate through the read data and add the even and odd indices to the real
   // and imaginary components respectively 
   int sampIdx = 0;
   //for(int i = 0; i < data.size(); i += 2)
   for(int i = 0; i < num_chunks; i += 2){
     _samples[sampIdx].real(data[i]);
     _samples[sampIdx].imag(data[i+1]);
     sampIdx++;
   } 
 
   // Close the file
   input_file.close();
 
   return status;
}
