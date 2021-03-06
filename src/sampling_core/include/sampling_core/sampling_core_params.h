#pragma once

#include <geometry_msgs/Point.h>
#include <ros/ros.h>

#include <Eigen/Dense>
#include <string>
#include <vector>

namespace sampling {
namespace core {

const std::string KDataPackage = "sampling_data";
const int KModelUpdateFrequencyCount = 1;
const int KInitSampleSize = 5;
const double KInitSampleRatio = 0.05;

class SamplingCoreParams {
 public:
  SamplingCoreParams();

  bool LoadFromRosParams(ros::NodeHandle &ph);

  Eigen::MatrixXd test_locations;

  std::vector<geometry_msgs::Point> test_locations_msg;

  std::vector<std::string> agent_ids;

  Eigen::VectorXd ground_truth_measurements;

  std::vector<double> ground_truth_measurements_vec;

  bool enable_performance_evaluation;

  Eigen::MatrixXd initial_locations;

  std::vector<geometry_msgs::Point> initial_locations_msg;

  Eigen::VectorXd initial_measurements;

  bool LoadMatrix(const std::string &path, Eigen::MatrixXd &data);

  bool LoadVector(const std::string &path, Eigen::VectorXd &data);

  void MatrixToMsg(const Eigen::MatrixXd &data,
                   std::vector<geometry_msgs::Point> &msg);

  int model_update_frequency_count;

};  // namespace scene
}  // namespace core
}  // namespace sampling