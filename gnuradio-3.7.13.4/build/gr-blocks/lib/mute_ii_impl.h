/* -*- c++ -*- */
/*
 * Copyright 2004,2013 Free Software Foundation, Inc.
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

#ifndef INCLUDED_BLOCKS_MUTE_II_IMPL_H
#define INCLUDED_BLOCKS_MUTE_II_IMPL_H

#include <gnuradio/blocks/mute_ii.h>

namespace gr {
  namespace blocks {

    class mute_ii_impl : public mute_ii
    {
    private:
      bool d_mute;

    public:
      mute_ii_impl(bool mute);
      ~mute_ii_impl();

      bool mute() const { return d_mute; }
      void set_mute(bool mute) { d_mute = mute; }
      void set_mute_pmt(pmt::pmt_t msg) { set_mute(pmt::to_bool(msg)); }

      int work(int noutput_items,
               gr_vector_const_void_star &input_items,
               gr_vector_void_star &output_items);
    };

  } /* namespace blocks */
} /* namespace gr */

#endif /* INCLUDED_BLOCKS_MUTE_II_IMPL_H */
