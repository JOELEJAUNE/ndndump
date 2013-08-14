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

#ifndef _NDNB_PARSER_BASE_ATTR_H_
#define _NDNB_PARSER_BASE_ATTR_H_

#include "ndnb-parser-udata.h"

namespace ns3 {
namespace NdnbParser {

/**
 * \ingroup ndnx-ndnb
 * \brief Virtual base class providing a common storage for ATTR
 * and DATTR ndnb-encoded blocks
 *
 * \see http://www.ndnx.org/releases/latest/doc/technical/BinaryEncoding.html
 */
class BaseAttr : public Block
{
public:
  Ptr<Udata> m_value; ///< \brief Value of the attribute
};

}
}

#endif // _NDNB_PARSER_BASE_ATTR_H_
