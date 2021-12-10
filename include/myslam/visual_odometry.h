//
// Created by chan on 2021/12/9.
//

#ifndef VISUALODOMETRY_VISUAL_ODOMETRY_H
#define VISUALODOMETRY_VISUAL_ODOMETRY_H
#include "myslam/backend.h"
#include "myslam/common_include.h"
#include "myslam/dataset.h"
#include "myslam/frontend.h"
#include "myslam/viewer.h"

namespace myslam {

/**
 * VO 对外接口
 */
    class VisualOdometry {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
        typedef std::shared_ptr<VisualOdometry> Ptr;

        /// constructor with config file
        VisualOdometry(std::string &config_path);

        /**
         * do initialization things before run
         * @return true if success
         */
        bool Init();

        /**
         * start vo in the dataset
         */
        void Run();

        /**
         * Make a step forward in dataset
         */
        bool Step();

        /// 获取前端状态
        FrontendStatus GetFrontendStatus() const { return frontend_->GetStatus(); }

    private:
        bool inited_ = false;
        std::string config_file_path_;

        Frontend::Ptr frontend_ = nullptr;
        Backend::Ptr backend_ = nullptr;
        Map::Ptr map_ = nullptr;
        Viewer::Ptr viewer_ = nullptr;

        // dataset
        Dataset::Ptr dataset_ = nullptr;
    };
}  // namespace myslam

#endif //VISUALODOMETRY_VISUAL_ODOMETRY_H
