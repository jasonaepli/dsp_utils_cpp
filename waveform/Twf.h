#ifndef TWF_H
#define TWF_H

#include <complex>
#include <memory>

class Twf {
public:
  // Constructor
  //Twf();

  // Copy Constructor
  //Twf( Twf & other ); 
  // TODO: Move Constructor


  // TODO: Destructor

  int num_samps; // The number of complex samples
  std::shared_ptr<std::complex<double>[]> samps; // Pointer to the sample array
  double pass_bw__Hz; // The passband bandwidth in Herz
  double stop_bw__Hz; // The passband bandwidth in Herz
  uint32_t num_leading_transients; // Number of samples that are transients at the beginning
  uint32_t num_trailing_transients; // Number of samples that are transients at the end
  double sample_rate__Hz; // The sample rate of the waveform

  // TODO: Are these even worthwhile?
  void set_num_samples(int num);
  void set_samples( std::shared_ptr<std::complex<double>[]> p_samps );
  void set_pass_bw__Hz(double bw);
  void set_stop_bw__Hz(double bw);
  void set_leading_transients(uint32_t trans);
  void set_trailing_transients(uint32_t trans);

};

#endif
