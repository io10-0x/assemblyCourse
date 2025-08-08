//SDPX-License-Identifier: MIT

pragma solidity 0.8.20;

import {Base_TestV1, HorseStore} from "./Base_TestV1.t.sol";
import {HuffDeployer} from "foundry-huff/HuffDeployer.sol";
import {IHorseStore} from "../../src/IHorseStore.sol";

contract HorseStoreHuff is Base_TestV1 {
    string constant HUFF_LOCATION = "HorseStore";

    function setUp() public override {
        horseStore = IHorseStore(HuffDeployer.deploy(HUFF_LOCATION));
    }
}
