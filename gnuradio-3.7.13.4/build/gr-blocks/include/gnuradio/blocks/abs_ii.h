/* -*- c++ -*- */
/*
 * Copyright 2012 Free Software Foundation, Inc.
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

#ifndef INCLUDED_BLOCKS_ABS_II_H
#define INCLUDED_BLOCKS_ABS_II_H

#include <gnuradio/blocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace blocks {

    /*!
     * \brief output[m] = abs(input[m]) for all M streams.
     * \ingroup boolean_operators_blk
     *
     * \details
     * absolute value of data stream (Strip sign)
     */
    class BLOCKS_API abs_ii : virtual public sync_block
    {

    public:

      // gr::blocks::abs_ii::sptr
      typedef boost::shared_ptr<abs_ii> sptr;

      /*!
       * \brief Create an instance of abs_ii
       */
      static sptr make(size_t vlen=1);
    };

  } /* namespace blocks */
} /* namespace gr */

#endif /* INCLUDED_BLOCKS_ABS_II_H */
