/*
 * main.cpp
 *
 *  Created on: Jul 23, 2018
 *      Author: zhangyajia
 */


#include "lateral_trajectory_optimizer_interface.h"

#include "IpIpoptApplication.hpp"
#include "IpSolveStatistics.hpp"

#include <fstream>
#include <vector>
#include <string>

extern bool optimize();

//std::vector<double> split(const std::string &str,
//                          const std::string &delims) {
//  std::vector<double> tokens;
//  std::string::size_type last_index = str.find_first_not_of(delims, 0);
//  std::string::size_type index = str.find_first_of(delims, last_index);
//
//  while (std::string::npos != index || std::string::npos != last_index) {
//    tokens.push_back(std::atof(str.substr(last_index, index - last_index).c_str()));
//    last_index = str.find_first_not_of(delims, index);
//    index = str.find_first_of(delims, last_index);
//  }
//  return tokens;
//}
//
//std::vector<std::pair<double, double>> read_boundary(const std::string& filename) {
//  std::ifstream file_in;
//  file_in.open(filename.c_str());
//
//  std::string line = "";
//  while (true) {
//
//  }
//}

int main() {
  bool res = optimize();
  return 0;
}

bool optimize() {
  std::array<double, 3> d_state = {-0.367117, -0.367264, -0.36727};

//  std::array<double, 3> d_state = {-0.367117, 0, 0};
  double delta_s = 1.0;

  double lateral_third_order_derivative_max = 1.0;

  constexpr double offset = 3.0;
  std::vector<std::pair<double, double>> lateral_bounds = {
      {-1.74277, 1.76625},
      {-1.73191, 1.77659},
      {-1.71318, 1.79483},
      {-1.69308, 1.81441},
      {-1.68468, 1.82227},
      {-1.68074, 1.8256},
      {-1.68021, 1.82543},
      {-1.68228, 1.82257},
      {-1.68302, 1.82091},
      {-1.69296, 1.80996},
      {-1.70187, 1.80005},
      {-1.71569, 1.78534},
      {-1.7346, 1.76571},
      {-1.74903, 1.75083},
      {-1.76883, 1.73094},
      {-1.79021, 1.7099},
      {-1.8124, 1.6886},
      {-1.83267+ offset, 1.66981},
      {-1.85224+ offset, 1.65243},
      {-1.88007+ offset, 1.62759},
      {-1.90518+ offset, 1.60634},
      {-1.91903+ offset, 1.59732},
      {-1.94198+ offset, 1.58026},
      {-1.96384+ offset, 1.5654},
      {-1.9764+ offset, 1.56107},
      {-1.9956+ offset, 1.55141},
      {-2.01325+ offset, 1.54468},
      {-2.02889, 1.54135},
      {-2.03967, 1.54455},
      {-2.04832, 1.5517},
      {-2.05071, 1.55312},
      {-2.05474, 1.54549},
      {-2.047, 1.54962},
      {-2.04431, 1.54871},
      {-2.03211, 1.55734},
      {-2.01867, 1.5672},
      {-2.00693, 1.57533},
      {-1.983, 1.59563},
      {-1.96116, 1.61387},
      {-1.93613, 1.6353},
      {-1.9081, 1.65973},
      {-1.8824, 1.68187},
      {-1.84686, 1.7138},
      {-1.80876, 1.7483},
      {-1.78138, 1.77207},
      {-1.73829, 1.81158},
      {-1.69147, 1.8548},
      {-1.66515, 1.87753},
      {-1.62237, 1.91671},
      {-1.58397, 1.95151},
      {-1.55969, 1.97218},
      {-1.52729, 2.00119},
      {-1.50816, 2.02681},
      {-1.49634, 2.04552},
      {-1.48856, 2.06029},
      {-1.49005, 2.06594},
      {-1.50338, 2.05976},
      {-1.5276, 2.04278},
      {-1.57546, 2.00217},
      {-1.63738, 1.94771},
      {-1.72134, 1.87116},
      {-1.79385, 1.8062 - offset},
      {-1.92034, 1.68735 - offset},
      {-2.07559, 1.53976 - offset},
      {-2.14618, 1.44594 - offset},
      {-2.06668, 1.48609- offset},
      {-1.97695, 1.53815- offset},
      {-1.89508, 1.5847- offset},
      {-1.81565, 1.63076- offset},
      {-1.73729, 1.67803- offset},
      {-1.67054, 1.71596- offset},
      {-1.60592, 1.75408- offset},
      {-1.54632, 1.78942},
      {-1.4963, 1.81752},
      {-1.45598, 1.83824},
      {-1.42013, 1.85705},
      {-1.3914, 1.87098},
      {-1.37163, 1.87839},
      {-1.35912, 1.88092},
      {-1.35131, 1.88112},
      {-1.34963, 1.87763},
      {-1.35558, 1.86884},
      {-1.36463, 1.85935},
      {-1.38397, 1.84186},
      {-1.40514, 1.82484},
      {-1.43442, 1.80197},
      {-1.46785, 1.77715},
      {-1.50788, 1.74789},
      {-1.55326, 1.71535},
      {-1.60207, 1.68146},
      {-1.65499, 1.64541},
      {-1.71067, 1.60851},
      {-1.76815, 1.57165},
      {-1.82519, 1.53694},
      {-1.87952, 1.50665},
      {-1.91874, 1.49292},
      {-1.96083, 1.46963},
      {-1.86292, 1.58444},
      {-1.73924, 1.71752},
      {-1.64361, 1.82259}};

  auto ptr_interface = new LateralTrajectoryOptimizerInterface(
      d_state[0], d_state[1], d_state[2], delta_s,
      lateral_third_order_derivative_max, lateral_bounds);

  ptr_interface->set_objective_weights(
      1.0,
      20.0,
      30.0,
      1.0);


  Ipopt::SmartPtr<Ipopt::TNLP> problem = ptr_interface;

  // Create an instance of the IpoptApplication
  Ipopt::SmartPtr<Ipopt::IpoptApplication> app = IpoptApplicationFactory();

  // app->Options()->SetIntegerValue("print_level", 0);
  app->Options()->SetIntegerValue("max_iter", 300);
  app->Options()->SetIntegerValue("acceptable_iter", 5);
  app->Options()->SetNumericValue("tol", 1.0e-3);
  app->Options()->SetNumericValue("acceptable_tol", 1.0e-3);
//  app->Options()->SetStringValue("mehrotra_algorithm", "yes");

  Ipopt::ApplicationReturnStatus status = app->Initialize();
  if (status != Ipopt::Solve_Succeeded) {
    std::cout << "*** Error during initialization!" << std::endl;
    return false;
  }

  status = app->OptimizeTNLP(problem);

  if (status == Ipopt::Solve_Succeeded ||
      status == Ipopt::Solved_To_Acceptable_Level) {
    // Retrieve some statistics about the solve
    Ipopt::Index iter_count = app->Statistics()->IterationCount();
    std::cout << "*** The problem solved in " << iter_count << " iterations!" << std::endl;

    Ipopt::Number final_obj = app->Statistics()->FinalObjective();
    std::cout << "*** The final value of the objective function is " << final_obj
           << '.' << std::endl;
  } else {
    std::cout << "Return status: " << int(status) << std::endl;
  }

  std::vector<double> opt_d;
  std::vector<double> opt_d_prime;
  std::vector<double> opt_d_pprime;
  ptr_interface->GetOptimizationResult(&opt_d, &opt_d_prime, &opt_d_pprime);

  std::ofstream file_out("result.txt");
  for (const auto& b : lateral_bounds) {
    file_out << b.first << "\t";
  }
  file_out << std::endl;

  for (const auto& b : lateral_bounds) {
    file_out << b.second << "\t";
  }
  file_out << std::endl;

  for (auto& d : opt_d) {
    file_out << d << "\t";
  }
  file_out << std::endl;

  for (auto& d_prime : opt_d_prime) {
    file_out << d_prime << "\t";
  }
  file_out << std::endl;

  for (auto& d_pprime : opt_d_pprime) {
    file_out << d_pprime << "\t";
  }
  file_out << std::endl;

  file_out << delta_s << std::endl;
  file_out << d_state[0] << std::endl;
  file_out << d_state[1] << std::endl;
  file_out << d_state[2] << std::endl;

  file_out.flush();
  file_out.close();

  return status == Ipopt::Solve_Succeeded ||
         status == Ipopt::Solved_To_Acceptable_Level;
}
