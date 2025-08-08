//SDPX-License-Identifier: MIT

pragma solidity 0.8.20;

import {Base_TestV1, HorseStore} from "./Base_TestV1.t.sol";
import {HorseStoreYul} from "../../src/HorseStoreYul.sol";
import {IHorseStore} from "../../src/IHorseStore.sol";
import {Test, console} from "lib/forge-std/src/Test.sol";

contract HorseStorePureYulTest1 is Base_TestV1 {
    function setUp() public override {
        bytes
            memory yulCodeCopy = hex"603680600a5f395ff3fe5f3560e01c8063cdfead2e1460245763e026c01714601b575f80fd5b5f545f5260205ff35b602436106032576004355f55005b5f80fd";
        address horseAddy;
        assembly {
            let yulCodeLength := mload(yulCodeCopy)
            let datastart := add(yulCodeCopy, 0x20)

            horseAddy := create(0, datastart, yulCodeLength)
        }
        console.log(horseAddy);
        require(horseAddy != address(0), "Create failed");
        horseStore = IHorseStore(horseAddy);
    }
}
