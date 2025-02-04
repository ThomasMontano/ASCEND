/* -*- c++ -*- */
/*
 * Copyright 2004,2009,2010,2012 Free Software Foundation, Inc.
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <multiply_const_vii_impl.h>
#include <gnuradio/io_signature.h>

namespace gr {
  namespace blocks {

    multiply_const_vii::sptr multiply_const_vii::make(std::vector<int> k)
    {
      return gnuradio::get_initial_sptr(new multiply_const_vii_impl(k));
    }

    multiply_const_vii_impl::multiply_const_vii_impl(std::vector<int> k)
      : sync_block ("multiply_const_vii",
		       io_signature::make (1, 1, sizeof (int)*k.size()),
		       io_signature::make (1, 1, sizeof (int)*k.size())),
      d_k(k)
    {
    }

    int
    multiply_const_vii_impl::work(int noutput_items,
		      gr_vector_const_void_star &input_items,
		      gr_vector_void_star &output_items)
    {
      int *iptr = (int *)input_items[0];
      int *optr = (int *)output_items[0];

      int nitems_per_block = output_signature()->sizeof_stream_item(0)/sizeof(int);

      for (int i = 0; i < noutput_items; i++)
	for (int j = 0; j < nitems_per_block; j++)
	  *optr++ = *iptr++ * d_k[j];

      return noutput_items;
    }

  } /* namespace blocks */
} /* namespace gr */
