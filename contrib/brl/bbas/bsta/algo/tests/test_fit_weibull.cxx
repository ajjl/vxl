#include <testlib/testlib_test.h>
#include <bsta/algo/bsta_fit_weibull.h>
#include <vcl_string.h>
#include <vcl_limits.h>
#include <vcl_iostream.h>

template <class T>
void test_fit_weibull_type(T epsilon, const vcl_string& type_name)
{
  
  T sample_mean = T(0.404), sample_std_dev = T(0.33);
  bsta_weibull_cost_function wcf(sample_mean, sample_std_dev);
  bsta_fit_weibull<T> fw(&wcf);
  T k = T(0);
  fw.init(k);
  fw.solve(k);
  T residual = fw.residual();
  T lambda = fw.lambda(k);

  TEST_NEAR(("shape param k <"+type_name+">").c_str(),
            k, static_cast<T>(1.2309439), epsilon);

  TEST_NEAR(("shape param lambda <"+type_name+">").c_str(),
            lambda, static_cast<T>(0.43221056), epsilon);
}


MAIN( test_fit_weibull )
{
  START ("fit_weibull");
  test_fit_weibull_type(float(1e-5),"float");
  test_fit_weibull_type(double(1e-8),"double");
  SUMMARY();
}


