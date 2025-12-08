//------------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2025 Basler AG
//  http://www.baslerweb.com
//------------------------------------------------------------------------------
/*!
 \file

 \brief
    Contains utility functions for floating-point comparison
*/

#pragma once

#include <cmath>

/*!
 * \namespace Pylon
 * \brief The Pylon namespace
 */
namespace Pylon
{
    /*!
     * \namespace Pylon::DataProcessing
     * \brief The DataProcessing namespace
     */
    namespace DataProcessing
    {
        /*! \brief Default tolerance for comparing floating point values.
         */
        static constexpr double gs_defaultComparisonTolerance = 1e-10;

        /*!
            \brief Compares two double values for similarity within a given tolerance.
            \param[in] a The first double value to compare.
            \param[in] b The second double value to compare.
            \param[in] tolerance The tolerance used for the comparison of floating point values.
            \error
                - Doesn't throw C++ exceptions.
            \return Returns true if similar within the given tolerance or false otherwise.
         */
        inline bool IsSimilar(double a, double b, double tolerance = gs_defaultComparisonTolerance)
        {
            return std::fabs(a - b) <= tolerance;
        }
    }
}
