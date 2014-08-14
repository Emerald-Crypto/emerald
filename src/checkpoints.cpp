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
            (   999, uint256("0x5788afcaf6fb0549ae71f40fd1d3ee31f75aa2acfbe12ba8eb95ad79e1dd7a62"))
            (  9999, uint256("0x081bcd85c658f8814c6f90d52f2cd2a06b7338831c7b5e3f849b70ad55182def"))
            ( 49999, uint256("0xa5b35ebbbd7385f8a6436223512ecca681f0b63d89eaba1ba05c630e74d402cd"))
            ( 99999, uint256("0xe9ea11f2160108bb6d4857f65530183076cba1fd023f328c79da56239a87247a"))
            (149999, uint256("0x52c51d8db0d72038940c6a176f71a9aac980d6da05b3db4fe38562c437d56689"))
            (199999, uint256("0x1af645aa30ee715c76d0bb7ae8a4412d0b2c80f8236859bd9a48df19d442fdad"))
            (249999, uint256("0xd7079ff0374c575a00dbb792adf42c01fcf54b7e2cb27a83aec4af66472e756f"))
            (299999, uint256("0x486f9f5a2eb45f3f2b977f4819537fabbd56e9a4edf85f7519e4e685854b94bb"))
            (320999, uint256("0x9517190d0cccca52ab3f3fdbb04c8740e8ae01e3e61cb14df27f109fd53aa99a"))
            (420999, uint256("0xa36c96ce708ab63a102970fee48a6ed7ed5e0cf0c72146d794fe986e8bf7c53e"))
            (520999, uint256("0x2278839f07b16770442504929b862994d4ef6445773e3ba3e5d34eede3cb1ae4"))
            (620999, uint256("0x0b743259ce1ddef706104c2605dccaa815eb338fbebc9fb31619ea7f1f16ddaa"))
            (720999, uint256("0x623a89da20b5afb812122542c20c60f3e2fb7735f24f6483b56740b3f1339506"))
            (820999, uint256("0xd488013888a18181906896ecee15d6adc1b0fe02c7e3c135e7d169b5c9b46041"))
            (920999, uint256("0xb8b1c2fe671482462b1bc4b4eba8eb9b35ddb392453b5fbd2f2c7cca15b5c196"))
            (1020999, uint256("0x162378e68eaa4f7d261428f716da79c5caef38b5edffee281c6637a00be8d806"))
            (1120999, uint256("0x5ce2e0700bc6a86845a11e12f9a568964688a3ab18c3226553e107c9623a5eb9"))
            (1220999, uint256("0x42d780abbedb09a1a9aab8fe9758e423699b49408b52c4ba347b5c48dc4fffc3"))
            (1320999, uint256("0xe4d15a05b01e6743d002c659e9d767ec7027db8aa8146c1973dd728c5b5a7cde"))
            (1420999, uint256("0xf7f44ef393f47260bcbdd4870c60d30b92b3cc6dbb9d621a4f50a939d29f7bbe"))
            (1550999, uint256("0x22f2eac705d5839b6db26b815b7f84adb960c9194384aa0a6031a22c78938381"))
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
