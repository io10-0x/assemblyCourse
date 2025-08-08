pragma solidity 0.8.20;

import {ERC721Enumerable, ERC721} from "@openzeppelin/contracts/token/ERC721/extensions/ERC721Enumerable.sol";

/*
 * @title HorseStore
 * @author equestrian_lover_420
 * @notice An NFT that represents a horse. Horses should be fed daily to keep happy, ideally several times a day.
 */
contract TestInheritance is ERC721Enumerable {
    string constant NFT_NAME = "HorseStore";
    string constant NFT_SYMBOL = "HS";

    mapping(uint256 id => uint256 lastFedTimeStamp)
        public horseIdToFedTimeStamp;

    constructor() ERC721(NFT_NAME, NFT_SYMBOL) {}
}
