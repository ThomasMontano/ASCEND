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

#ifndef INCLUDED_BLOCKS_AND_CONST_SS_H
#define INCLUDED_BLOCKS_AND_CONST_SS_H

#include <gnuradio/blocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace blocks {

    /*!
     * \brief output[m] = input[m] & value for all M streams.
     * \ingroup boolean_operators_blk
     *
     * \details
     * Bitwise boolean AND of constant \p k with the data stream.
     */
    class BLOCKS_API and_const_ss : virtual public sync_block
    {

    public:

      // gr::blocks::and_const_ss::sptr
      typedef boost::shared_ptr<and_const_ss> sptr;

      /*!
       * \brief Create an instance of and_const_ss
       * \param k AND constant
       */
      static sptr make(short k);

      /*!
       * \brief Return AND constant
       */
      virtual short k() const = 0;

      /*!
       * \brief Set AND constant
       */
      virtual void set_k(short k) = 0;
    };

  } /* namespace blocks */
} /* namespace gr */

#endif /* INCLUDED_BLOCKS_AND_CONST_SS_H */
