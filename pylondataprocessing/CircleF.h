//------------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2023-2025 Basler AG
//  http://www.baslerweb.com
//------------------------------------------------------------------------------
/*!
\file
\brief Contains a data class that represents the CircleF data type.
*/

#pragma once

#include <pylon/stdinclude.h>
#include <pylondataprocessing/PointF2D.h>

#pragma pack(push, 1)

namespace Pylon
{
    namespace DataProcessing
    {
        /*! \brief The data of a CVariant object with the VariantDataType_CircleF data type.
         */
        struct SCircleF
        {
            /*! \brief Creates a circle and initializes it with 0.
             */
            SCircleF()
                : Radius(0.0)
            {
            }

            /*! \brief Creates a circle and initializes it.
                \param[in] centerX The x coordinate of the center of the circle.
                \param[in] centerY The y coordinate of the center of the circle.
                \param[in] radius The radius of the circle.
            */
            SCircleF(double centerX, double centerY, double radius)
                : Center(centerX, centerY)
                , Radius(radius)
            {
            }

            /*! \brief Creates a circle and initializes it.
                \param[in] center The center of the circle.
                \param[in] radius The radius of the circle.
            */
            SCircleF(SPointF2D center, double radius)
                : Center(center)
                , Radius(radius)
            {
            }

            /*!
                \brief Compares two SCircleF instances for equality.
                \param[in] rhs The right-hand side object to compare with.
                \error
                 - Doesn't throw C++ exceptions.
                \return Returns true if equal or false otherwise.
             */
            bool operator == (const SCircleF& rhs) const
            {
                return (    (Center == rhs.Center)
                        &&  (Radius == rhs.Radius));
            }

            /*!
                \brief Compares two SCircleF instances for inequality.
                \param[in] rhs The right-hand side object to compare with.
                \error
                 - Doesn't throw C++ exceptions.
                \return Returns true if not equal or false otherwise.
             */
            bool operator != (const SCircleF& rhs) const
            {
                return ((*this == rhs) == false);
            }

            /*!
                \brief Compares two SCircleF instances for similarity within a given tolerance.
                \param[in] rhs The right-hand side object to compare with.
                \param[in] tolerance The tolerance used for the comparison of floating point values.
                \error
                    - Doesn't throw C++ exceptions.
                \return Returns true if similar within the given tolerance or false otherwise.
             */
            bool IsSimilar(const SCircleF& rhs, double tolerance = gs_defaultComparisonTolerance) const
            {
                return (    (Center.IsSimilar(rhs.Center, tolerance) == true)
                        &&  (DataProcessing::IsSimilar(Radius, rhs.Radius, tolerance) == true));
            }

            SPointF2D Center; //!< \brief The center of the circle.
            double Radius;    //!< \brief The radius of the circle.
        };
    }
}

#pragma pack(pop)
