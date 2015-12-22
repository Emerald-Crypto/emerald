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
			(1599999, uint256("0xdbe9932f81805a024b8f4fa0e474d3f43585311f6f6ed9b22ce380f1603a7f9b"))
			(1600000, uint256("0x2000d4aeedf60c5749bb69911a5b9fa960b0ba340432c8292fd454c908daac41"))
			(1600001, uint256("0x00f41131b1cb9316cc626ab336909eac82b9b0ad9cdf1fc1039de5f2fee3c973"))
			(1602099, uint256("0xc2584591289d987515db9db61472c83381ea9fc3efa3e3f1831c80d69991a4ad"))
			(1602879, uint256("0x6bd6e6198fa1d30e6c63631379e4f4117dfdc12d6369d296cbf48ec0654610ca"))
			(1604099, uint256("0xb31e5cf03c446964675889ad7ddc3807fe8b8a3351279b447c04c7b2335d1fac"))
			(1688888, uint256("0xac6f0a75b9cd7a5a71e94dd0055e0bac8f6c591d527c21541f6cb2a768c3afa8"))
			(1792464, uint256("0xa244296f4a8e691bbd18e631e8e22c6de4994c0bc32008c03f26767774d12071"))
			(1800000, uint256("0xfe013454ef287f154a60444b50ec2a1cebb3ec6aaa75f57e657e34b34a83cbe4"))
			(1899998, uint256("0xc9c2d4ea1ef806e72eb575e4cd1a71e2391fc5e1eda7c83818cf0f8d5a79711e"))
			(2000000, uint256("0x77afc9b139cb3d387912a966dd0cea8c514e5909d316e43f11510685286568a0"))
			(2010000, uint256("0xc1c0a6ec810990f488fcd35f9ba02e65eb8bea53d85988c1bdffe7bbeed9df30"))
			(2020000, uint256("0xcf1e41e827b22f07e1e28d959b75cfd4a1634f9007ecb2c7856c9f0c0474f23b"))
			(2030000, uint256("0x1a37ccfc0e3789c96c2dc1c15e48cb94ba1fdfc90c133e22f6fbdc73c8f6a469"))
			(2040002, uint256("0x639320bbbe437673e024d42034e0c77a6c95b9f0ddb554f0ba0fa07150d5a2b2"))
			(2050000, uint256("0x3b5bdc1bd29a5d83d50f6505284ccd29f5edf13d3bfb29456fd888227e526dbf"))
			(2060500, uint256("0x955131f17619c0a6e11fb4b04ee6d7179b894e111dd9b312fffd0674f9482a8b"))
			(2200000, uint256("0x80156fc7bfe55b561e770f6f6c5f4e35bb5b0e6abfc22aec4e120e98cb805296"))
		    (2300000, uint256("0x588e732bbad22487846535754d79e7b13cc900df4e85a781832df5f38cecc64d"))
			(2400000, uint256("0x4e4ba04bfcabdca27632812d5e0b4525b36b48a88f0b3109cd71f888d00c5975"))
			(2500000, uint256("0x94eb7bfa6c8f02a0c8b39c946deebf730950160ef8316cb763fddc69c155745a"))
			(2600000, uint256("0xc56159b69c10655b5d019c59f155f2113aee1087e3c0cb6e82f943fe01b2b0f1"))
			(2700000, uint256("0x89db22bb550a93cfba8f74e102802c49e7b5ac50bf8909e85bf252bce45204be"))
			(2778170, uint256("0x804784b7a60bdcd0b93d81a80a0d5d1968e0421f745347ad9d679cfd120bfd96"))
			(3200008, uint256("0x2543c18e7c1debac80b6a9366cd3bc2721adae7b6fe9da402599478b3b0826cc"))
			(3211017, uint256("0x737592dadcf505f43bff9a8c72927838631255d7ac1040a4adf8b1661169d86c"))
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
