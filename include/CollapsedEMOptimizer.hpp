#ifndef COLLAPSED_EM_OPTIMIZER_HPP
#define COLLAPSED_EM_OPTIMIZER_HPP

#include <unordered_map>

#include "tbb/atomic.h"
#include "tbb/task_scheduler_init.h"

#include "ReadExperiment.hpp"
#include "SalmonOpts.hpp"

#include "cuckoohash_map.hh"
#include "Eigen/Dense"

class BootstrapWriter;

class CollapsedEMOptimizer {
    public:
        using VecType = std::vector<tbb::atomic<double>>;
        using SerialVecType = std::vector<double>;
        CollapsedEMOptimizer();

        template <typename ExpT>
        bool optimize(ExpT& readExp,
                      SalmonOpts& sopt,
                      double tolerance = 0.01,
                      uint32_t maxIter = 1000);

        template <typename ExpT>
        bool gatherBootstraps(
                ExpT& readExp,
                SalmonOpts& sopt,
                BootstrapWriter* bootstrapWriter,
                double relDiffTolerance,
                uint32_t maxIter);
};

#endif // COLLAPSED_EM_OPTIMIZER_HPP
