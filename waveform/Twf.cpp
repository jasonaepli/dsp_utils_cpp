#include <complex>
#include <memory>

#include "Twf.h"

// Constructor
/*Twf::Twf() {
    num_samps = 0; //std::nan("0");
    samps = nullptr;
    pass_bw__Hz = 0;//std::nan("0");
    stop_bw__Hz = 0;//std::nan("0");
    num_leading_transients = 0;//std::nan("0");
    num_trailing_transients = 0;//std::nan("0");
    sample_rate__Hz = 0;//std::nan("0");
}

  // Copy Constructor
Twf::Twf( Twf & other ) {
    num_samps = other.num_samps;
    samps = other.samps;
    pass_bw__Hz = other.pass_bw__Hz;
    stop_bw__Hz = other.stop_bw__Hz;
    num_leading_transients = other.num_leading_transients;
    num_trailing_transients = other.num_trailing_transients;
    sample_rate__Hz = other.sample_rate__Hz;
}*/

// TODO: Move Constructor


// TODO: Destructor

// TODO: Are these even worthwhile?
void Twf::set_num_samples(int num) { num_samps = num; };
void Twf::set_samples( std::shared_ptr<std::complex<double>[]> p_samps ) { samps = p_samps; };
void Twf::set_pass_bw__Hz(double bw) { pass_bw__Hz = bw; };
void Twf::set_stop_bw__Hz(double bw) { stop_bw__Hz = bw; };
void Twf::set_leading_transients(uint32_t trans) { num_leading_transients = trans; };
void Twf::set_trailing_transients(uint32_t trans) { num_trailing_transients = trans; };

