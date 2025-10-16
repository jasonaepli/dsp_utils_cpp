#ifndef RECORD_H
#define RECORD_H

#include <complex>
#include <string>
#include <memory>
 
#include "../misc/common.h"

/**
* @brief Represents a record of a signal stored in memory as raw samples
 *
 * This class represents a record of a signal stored in memory as raw samples.
 * No metadata is embedded in the record and must be provided from another source.
 *
 * @param a The first integer operand.
 * @param b The second integer operand.
 * @return The sum of 'a' and 'b'.
 */

class Record { 
    public:
    // Virtual destructor - essential for proper cleanup in polymorphic classes
    virtual ~Record() = default;
   
    // Public member variables
    SampFormat sample_format;             // The format of the sample word
    BitDepth bits_per_sample;             // Number of bits per sample
    uint32_t num_samples;                 // Number of samples in the record
    double sample_rate__Hz;               // Sample rate in Hertz
    double time_of_first_sample__sse;     // Time of first sample in seconds since epoch
    double time_of_first_sample_frac__ps; // Fractional time of first sample in pico seconds

    // Pure virtual functions - must be implemented by derived classes
    virtual std::string get_path() = 0;
    virtual std::shared_ptr<std::complex<double>[]> get_samples() = 0;
    virtual void set_sample_format( SampFormat f ) = 0;
    virtual void set_bits_per_sample( BitDepth bits ) = 0;
    virtual void set_sample_rate__Hz( double fs ) = 0;
    virtual void set_time_of_first_sample__sse( double tofs__sse ) = 0;
    virtual void set_time_of_first_sample_frac__ps( double tofs_frac__ps ) = 0;
    
    virtual int read_samples() = 0;

protected:
    std::string _file_path;
    std::shared_ptr<std::complex<double>[]> _samples; 
    
};

#endif
