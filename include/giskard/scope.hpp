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

#ifndef GISKARD_SCOPE_HPP
#define GISKARD_SCOPE_HPP

#include <string>
#include <map>
#include <giskard/expressiontree.hpp>

namespace giskard
{
  class Scope
  {
    public:
      const KDL::Expression<double>::Ptr& find_double_expression(const std::string& reference_name) const
      {
        // TODO: throw exception here
        assert(has_double_expression(reference_name));

        std::map< std::string, KDL::Expression<double>::Ptr >::const_iterator it =
            double_references_.find(reference_name);

        return it->second;
      }

      const KDL::Expression<KDL::Vector>::Ptr& find_vector_expression(const std::string& reference_name) const
      {
        // TODO: throw exception here
        assert(has_vector_expression(reference_name));

        std::map< std::string, KDL::Expression<KDL::Vector>::Ptr >::const_iterator it =
            vector_references_.find(reference_name);

        return it->second;
      }

      const KDL::Expression<KDL::Rotation>::Ptr& find_rotation_expression(const std::string& reference_name) const
      {
        // TODO: throw exception here
        assert(has_rotation_expression(reference_name));

        std::map< std::string, KDL::Expression<KDL::Rotation>::Ptr >::const_iterator it =
            rotation_references_.find(reference_name);

        return it->second;
      }

      const KDL::Expression<KDL::Frame>::Ptr& find_frame_expression(const std::string& reference_name) const
      {
        // TODO: throw exception here
        assert(has_frame_expression(reference_name));

        std::map< std::string, KDL::Expression<KDL::Frame>::Ptr >::const_iterator it =
            frame_references_.find(reference_name);

        return it->second;
      }

      bool has_double_expression(const std::string& expression_name) const
      {
        return (double_references_.count(expression_name) == 1);
      }

      bool has_vector_expression(const std::string& expression_name) const
      {
        return (vector_references_.count(expression_name) == 1);
      }

      bool has_rotation_expression(const std::string& expression_name) const
      {
        return (rotation_references_.count(expression_name) == 1);
      }

      bool has_frame_expression(const std::string& expression_name) const
      {
        return (frame_references_.count(expression_name) == 1);
      }

      void add_double_expression(const std::string& reference_name, const KDL::Expression<double>::Ptr& expression)
      {
        // TODO: throw warning here
        assert(!has_double_expression(reference_name));

        double_references_[reference_name] = expression;
      }

      void add_vector_expression(const std::string& reference_name, const KDL::Expression<KDL::Vector>::Ptr& expression)
      {
        // TODO: throw warning here
        assert(!has_vector_expression(reference_name));

        vector_references_[reference_name] = expression;
      }

      void add_rotation_expression(const std::string& reference_name, const KDL::Expression<KDL::Rotation>::Ptr& expression)
      {
        // TODO: throw warning here
        assert(!has_rotation_expression(reference_name));

        rotation_references_[reference_name] = expression;
      }

      void add_frame_expression(const std::string& reference_name, const KDL::Expression<KDL::Frame>::Ptr& expression)
      {
        // TODO: throw warning here
        assert(!has_frame_expression(reference_name));

        frame_references_[reference_name] = expression;
      }

    private:
      std::map< std::string, KDL::Expression<double>::Ptr > double_references_;
      std::map< std::string, KDL::Expression<KDL::Vector>::Ptr > vector_references_;
      std::map< std::string, KDL::Expression<KDL::Rotation>::Ptr > rotation_references_;
      std::map< std::string, KDL::Expression<KDL::Frame>::Ptr > frame_references_;
  };
}

#endif // GISKARD_SCOPE_HPP
