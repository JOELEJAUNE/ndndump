/* -*- Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2011 University of California, Los Angeles
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Alexander Afanasyev <alexander.afanasyev@ucla.edu>
 */

#include "ns3/ccnb-parser-blob.h"

#ifdef NOT_NS3
#include <boost/iostreams/read.hpp>
#endif

namespace ns3 {
namespace CcnbParser {

Blob::Blob (Buffer::Iterator &start, uint32_t length)
{
  if (length==0) return;
  
#ifndef NOT_NS3
  start.Read (m_blob.Begin (), length);
#else
  m_blobSize = length;
  m_blob = boost::shared_ptr<char> (new char[length]);
  uint32_t read = boost::iostreams::read (start, m_blob.get (), length);
  if (read!=length)
    throw CcnbDecodingException ();
#endif
}

}
}
