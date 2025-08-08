//SDPX-License-Identifier: MIT

pragma solidity 0.8.20;

import {Base_TestV1, HorseStore} from "./Base_TestV1.t.sol";
import {HorseStoreYul} from "../../src/HorseStoreYul.sol";
import {IHorseStore} from "../../src/IHorseStore.sol";

contract HorseStoreYulTest is Base_TestV1 {
    function setUp() public override {
        horseStore = IHorseStore(address(new HorseStoreYul()));
    }
}
