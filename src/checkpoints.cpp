// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Emerald Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (     1, uint256("0x01aa92d97daf7fa2987ffb0ec5778f35cdaf8cb2948018e636482693b43ff9fd"))
            (    51, uint256("0x83ba6777c3527ee8996fa568ca214df7860405e9078f3b974adc540770287882"))
            (   131, uint256("0x7f0effa98470562fd5b31f8c539ce2ee89efde6a8282a11854001c67a480da33"))
            (   207, uint256("0xda14d64c6fbf20d7c78cb6f74aa578217b61097c7e16301f38af465ca7b1286d"))
            ( 31283, uint256("0xb052441feab637bb5a847af68fc4280fdbfd299d76a233bd988bd16b44afee64"))
            ( 38967, uint256("0x794fdb36a62bbe9ec6feb4bd53e7c474be00b5ff4d617454f74716f8b40813d2"))
            ( 91181, uint256("0xe7f5e652bc53b61486bd038ca225557c6ebc7a359b9720baf5b9584ee8d7000d"))
            ( 93407, uint256("0x6bc6980d144ec1155ea2a12e3c716ebe35af8e29ab1aa0acb6ae86df8fe9c608"))
			;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
