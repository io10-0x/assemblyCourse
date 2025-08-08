//SDPX-License-Identifier: MIT

pragma solidity 0.8.20;

import {Test, console} from "lib/forge-std/src/Test.sol";
import {HorseStore} from "../../src/HorseStore.sol";
import {IHorseStore} from "../../src/IHorseStore.sol";

abstract contract Base_TestV1 is Test {
    IHorseStore horseStore;

    function setUp() public virtual {
        horseStore = IHorseStore(address(new HorseStore()));
    }

    function test_readNumberOfHorses() public view {
        uint256 num = horseStore.readNumberOfHorses();
        assertEq(num, 0);
    }

    function test_updateNumberOfHorses() public {
        horseStore.updateHorseNumber(70);
        uint256 num = horseStore.readNumberOfHorses();
        assertEq(num, 70);
    }
}
