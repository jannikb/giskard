/*
 * Copyright (C) 2015 Georg Bartels <georg.bartels@cs.uni-bremen.de>
 * 
 * This file is part of giskard.
 * 
 * giskard is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <gtest/gtest.h>
#include <giskard/giskard.hpp>


class RotationGenerationTest : public ::testing::Test
{
   protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown(){}
};

TEST_F(RotationGenerationTest, AxisAngle)
{
  giskard::DoubleConstSpecPtr x(new giskard::DoubleConstSpec());
  x->set_value(1.0);
  giskard::DoubleConstSpecPtr y(new giskard::DoubleConstSpec());
  y->set_value(0.0);
  giskard::DoubleConstSpecPtr z(new giskard::DoubleConstSpec());
  z->set_value(0.0);
  giskard::DoubleConstSpecPtr angle(new giskard::DoubleConstSpec());
  angle->set_value(M_PI/2.0);

  giskard::VectorConstructorSpecPtr axis(new giskard::VectorConstructorSpec());
  axis->set(x, y, z);
 
  giskard::AxisAngleSpec spec;
  spec.set_axis(axis);
  spec.set_angle(angle);

  giskard::Scope scope;
  KDL::Rotation rot = spec.get_expression(scope)->value();
  KDL::Rotation rot2 = KDL::Rotation::Rot(KDL::Vector(1.0, 0.0, 0.0), M_PI/2.0);

  EXPECT_TRUE(KDL::Equal(rot, rot2));
}

TEST_F(RotationGenerationTest, AxisAngleEquality)
{
  giskard::DoubleConstSpecPtr x(new giskard::DoubleConstSpec());
  x->set_value(1.0);
  giskard::DoubleConstSpecPtr y(new giskard::DoubleConstSpec());
  y->set_value(0.0);
  giskard::DoubleConstSpecPtr z(new giskard::DoubleConstSpec());
  z->set_value(0.0);
  giskard::DoubleConstSpecPtr angle(new giskard::DoubleConstSpec());
  angle->set_value(M_PI/2.0);

  giskard::VectorConstructorSpecPtr axis1(new giskard::VectorConstructorSpec());
  giskard::VectorConstructorSpecPtr axis2(new giskard::VectorConstructorSpec());
  axis1->set(x, y, z);
  axis2->set(x, x, x);
 
  giskard::AxisAngleSpec s1, s2, s3, s4;
  s1.set_axis(axis1);
  s1.set_angle(angle);
  s2.set_axis(axis1);
  s2.set_angle(x);
  s3.set_axis(axis2);
  s3.set_angle(angle);
  s4.set_axis(axis1);
  s4.set_angle(angle);

  EXPECT_TRUE(s1.equals(s1));
  EXPECT_FALSE(s1.equals(s2));
  EXPECT_FALSE(s1.equals(s3));
  EXPECT_TRUE(s1.equals(s4));

  EXPECT_EQ(s1, s1);
  EXPECT_NE(s1, s2);
  EXPECT_NE(s1, s3);
  EXPECT_EQ(s1, s4);
}
