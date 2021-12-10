//
// Created by chan on 2021/12/9.
//

#include <gflags/gflags.h>
#include "myslam/visual_odometry.h"

DEFINE_string(config_file, "./config/default.yaml", "config file path");

int main(int argc, char **argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);

    myslam::VisualOdometry::Ptr vo(
            new myslam::VisualOdometry(FLAGS_config_file));
    assert(vo->Init() == true);
    vo->Run();


    google::ShutdownGoogleLogging();
    return 0;
}