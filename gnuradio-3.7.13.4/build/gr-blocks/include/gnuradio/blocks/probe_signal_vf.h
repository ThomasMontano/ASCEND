/* -*- c++ -*- */
/*
 * Copyright 2005,2012-2013 Free Software Foundation, Inc.
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

#ifndef INCLUDED_BLOCKS_PROBE_SIGNAL_VF_H
#define INCLUDED_BLOCKS_PROBE_SIGNAL_VF_H

#include <vector>
#include <gnuradio/blocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace blocks {

    /*!
     * \brief Sink that allows a vector of samples to be grabbed from Python.
     * \ingroup sink_blk
     * \ingroup measurement_tools_blk
     */
    class BLOCKS_API probe_signal_vf : virtual public sync_block
    {
    public:
      // gr::blocks::probe_signal_vf::sptr
      typedef boost::shared_ptr<probe_signal_vf> sptr;

      static sptr make(size_t size);

      virtual std::vector<float> level() const = 0;
    };

  } /* namespace blocks */
} /* namespace gr */

#endif /* INCLUDED_BLOCKS_PROBE_SIGNAL_VF_H */
