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

#ifndef _NDNB_PARSER_DTAG_H_
#define _NDNB_PARSER_DTAG_H_

#include "ndnb-parser-base-tag.h"

namespace ns3 {
namespace NdnbParser {

/**
 * \ingroup ndnx-ndnb
 * \brief Class to represent DTAG ndnb-encoded node
 *
 * \see http://www.ndnx.org/releases/latest/doc/technical/BinaryEncoding.html
 */
class Dtag : public BaseTag
{
public:
  /**
   * \brief Constructor that actually parsed ndnb-encoded DTAG block
   *
   * \param start buffer iterator pointing to the first nesting block or closing tag
   * \param dtag  dictionary code of DTAG (extracted from the value field)
   *
   * DTAG parsing is slightly hacked to provide memory optimization
   * for NS-3 simulations.  Parsing will be stopped after encountering
   * <Content> dtag.  Actual content (including virtual payload) will
   * be stored in Packet buffer
   *
   * \see http://www.ndnx.org/releases/latest/doc/technical/BinaryEncoding.html
   */
  Dtag (Buffer::Iterator &start, uint32_t dtag);

  virtual void accept( VoidNoArguVisitor &v )               { v.visit( *this ); }
  virtual void accept( VoidVisitor &v, boost::any param )   { v.visit( *this, param ); }
  virtual boost::any accept( NoArguVisitor &v )             { return v.visit( *this ); }
  virtual boost::any accept( Visitor &v, boost::any param ) { return v.visit( *this, param ); }

  uint32_t m_dtag; ///< \brief Dictionary code for DTAG
};

}
}

#endif // _NDNB_PARSER_DTAG_H_
