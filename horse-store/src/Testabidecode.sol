//SDPX-License-Identifier: MIT

pragma solidity 0.8.24;

contract test {
    function testDecode() external {
        bytes memory result = abi.encode("aaaa");
        abi.decode(result, (string));
    }
}
