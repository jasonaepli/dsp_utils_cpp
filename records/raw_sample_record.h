#ifndef RAW_SAMPLE_RECORD_H
#define RAW_SAMPLE_RECORD_H

#include <fstream>
#include <iostream> 
#include <vector>
#include <complex>
#include <string>
#include <memory>
#include <algorithm>

#include "record.h"
#include "../misc/common.h"

/**
* @brief Abstract representation a record of a signal stored in memory
 *
 * This is an abstract class representing a record of a signal stored in memory.
*/

class RawSampleRecord : public Record { 
    public:
    // Constructor
    RawSampleRecord(std::string path, SampFormat format, BitDepth bits, double fs, double tofs__sse, double tofs_frac__ps);

    // Implementation of pure virtual functions from Record base class
    std::string get_path() override;
    std::shared_ptr<std::complex<double>[]> get_samples() override;
    void set_sample_format( SampFormat f ) override;
    void set_bits_per_sample( BitDepth bits ) override;
    void set_sample_rate__Hz( double fs ) override;
    void set_time_of_first_sample__sse( double tofs__sse ) override;
    void set_time_of_first_sample_frac__ps( double tofs_frac__ps ) override;
    
    int read_samples() override;
};

#endif
