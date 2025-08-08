// SPDX-License-Identifier: GPL-3.0-only
pragma solidity 0.8.20;

contract HorseStoreYul {
    uint256 numberOfHorses;

    function updateHorseNumber(uint256 newNumberOfHorses) external {
        assembly {
            sstore(numberOfHorses.slot, newNumberOfHorses)
        }
    }

    function readNumberOfHorses() external view returns (uint256) {
        assembly {
            let freemempointer := mload(0x40)
            let numHorses := sload(numberOfHorses.slot)
            mstore(freemempointer, numHorses)
            return(freemempointer, add(freemempointer, 0x20))
        }
    }
}
