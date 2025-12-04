//------------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2023-2025 Basler AG
//  http://www.baslerweb.com
//------------------------------------------------------------------------------
/*!
\file
\brief Contains a data class that represents the PointF2D data type.
*/

#pragma once

#include <pylon/stdinclude.h>
#include <pylondataprocessing/Compare.h>

#pragma pack(push, 1)

namespace Pylon
{
    namespace DataProcessing
    {
        /*! \brief The data of a CVariant object with the VariantDataType_PointF2D data type.
            PointF2D can provide image coordinates in pixels and world coordinates in meters.
            The origin (0,0) of image coordinates defined by a PointF2D is the center of the top left image pixel.
         */
        struct SPointF2D
        {
            /*! \brief Creates a point and initializes it with (0,0).
             */
            SPointF2D()
                : X(0.0)
                , Y(0.0)
            {
            }
            
            /*! \brief Creates a point and initializes it with (x,y).
             */
            SPointF2D(double x, double y)
                : X(x)
                , Y(y)
            {
            }

            /*!
                \brief Compares two SPointF2D instances for equality.
                \param[in] rhs The right-hand side object to compare with.
                \error
                 - Doesn't throw C++ exceptions.
                \return Returns true if equal or false otherwise.
             */
            bool operator == (const SPointF2D& rhs) const
            {
                return (    (X == rhs.X)
                        &&  (Y == rhs.Y));
            }

            /*!
                \brief Compares two SPointF2D instances for inequality.
                \param[in] rhs The right-hand side object to compare with.
                \error
                 - Doesn't throw C++ exceptions.
                \return Returns true if not equal or false otherwise.
             */
            bool operator != (const SPointF2D& rhs) const
            {
                return ((*this == rhs) == false);
            }

            /*!
                \brief Compares two SPointF2D instances for similarity within a given tolerance.
                \param[in] rhs The right-hand side object to compare with.
                \param[in] tolerance The tolerance used for the comparison of floating point values.
                \error
                    - Doesn't throw C++ exceptions.
                \return Returns true if similar within the given tolerance or false otherwise.
             */
            bool IsSimilar(const SPointF2D& rhs, double tolerance = gs_defaultComparisonTolerance) const
            {
                return (    (DataProcessing::IsSimilar(X, rhs.X, tolerance) == true)
                        &&  (DataProcessing::IsSimilar(Y, rhs.Y, tolerance) == true));
            }

            double X; //!< \brief The x coordinate of the point.
            double Y; //!< \brief The y coordinate of the point.
        };
    }
}

#pragma pack(pop)
