//////////////////////////////////////////////////////////////////////////////
//    Copyright 2004, SenseGraphics AB
//
//    This file is part of H3D API.
//
//    H3D API is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    H3D API is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with H3D API; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//    A commercial license is also available. Please contact us at 
//    www.sensegraphics.com for more information.
//
//
/// \file HapticTriangleSet.h
/// \brief Header file for HapticTriangleSet
///
//
//////////////////////////////////////////////////////////////////////////////
#ifndef __HAPTICTRIANGLESET_H__
#define __HAPTICTRIANGLESET_H__

#include <HAPIHapticShape.h>

namespace H3D {

  /// A shape defined by a set of triangles.
  class HAPI_API HapticTriangleSet: public HAPIHapticShape {
  public:
    /// Constructor.
    HapticTriangleSet( const vector< Bounds::Triangle > &_triangles,
                       void *_userdata,
                       HAPISurfaceObject *_surface,
                       const H3D::ArithmeticTypes::Matrix4d & _transform ):
      HAPIHapticShape( _userdata, _surface, _transform ),
      triangles( _triangles ) {}

    template< class Iterator >
    HapticTriangleSet( Iterator begin,
                       Iterator end,
                       void *_userdata,
                       HAPISurfaceObject *_surface,
                       const H3D::ArithmeticTypes::Matrix4d & _transform ):
      HAPIHapticShape( _userdata, _surface, _transform ),
      triangles( begin, end ) {}

    virtual bool lineIntersect( const Vec3d &from, 
                                const Vec3d &to,
                                Bounds::IntersectionInfo &result );

    virtual void getConstraints( const Vec3d &point,
                                 H3DDouble radius,
                                 std::vector< PlaneConstraint > &constraints );

    /// The triangles.
    vector< Bounds::Triangle > triangles;
      
  };
}

#endif
