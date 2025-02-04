/* -*- c++ -*- */
/*
 * Copyright 2014 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

// WARNING: this file is machine generated. Edits will be overwritten

#ifndef INCLUDED_BLOCKS_TSB_VECTOR_SINK_I_IMPL_H
#define INCLUDED_BLOCKS_TSB_VECTOR_SINK_I_IMPL_H

#include <gnuradio/blocks/tsb_vector_sink_i.h>

namespace gr {
  namespace blocks {

    class tsb_vector_sink_i_impl : public tsb_vector_sink_i
    {
     private:
      std::vector<std::vector<int> > d_data;
      std::vector<tag_t> d_tags;
      int d_vlen;

     public:
      tsb_vector_sink_i_impl(int vlen, const std::string &tsb_key);
      ~tsb_vector_sink_i_impl();

      void reset() { d_data.clear(); }
      std::vector<std::vector<int> > data() const;
      std::vector<tag_t> tags() const;

      int work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace blocks
} // namespace gr

#endif /* INCLUDED_BLOCKS_TSB_VECTOR_SINK_I_IMPL_H */

