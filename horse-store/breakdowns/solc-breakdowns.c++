//0x608060405234801561000f575f80fd5b506101438061001d5f395ff3fe608060405234801561000f575f80fd5b5060043610610034575f3560e01c8063cdfead2e14610038578063e026c01714610054575b5f80fd5b610052600480360381019061004d91906100ba565b610072565b005b61005c61007b565b60405161006991906100f4565b60405180910390f35b805f8190555050565b5f8054905090565b5f80fd5b5f819050919050565b61009981610087565b81146100a3575f80fd5b50565b5f813590506100b481610090565b92915050565b5f602082840312156100cf576100ce610083565b5b5f6100dc848285016100a6565b91505092915050565b6100ee81610087565b82525050565b5f6020820190506101075f8301846100e5565b9291505056fea26469706673582212206647c0641c72fe752d7b11ec4b7112cf778846472076e40974f4f03482b6aab064736f6c63430008140033


PUSH1 0x80      //[0x80]
PUSH1 0x40      //[0x40, 0x80]
MSTORE          //[]
CALLVALUE       //[msg.value]
DUP1            //[msg.value, msg.value]
ISZERO          //[0x01, msg.value]
PUSH2 0x000f    //[0x000f, 0x01, msg.value]
JUMPI           //[msg.value]
PUSH0           //[0x00, msg.value]
DUP1            //[0x00, 0x00, msg.value]
REVERT          //[msg.value]
JUMPDEST        //[msg.value]
POP             //[]
PUSH2 0x0143    //[0x0143]
DUP1            //[0x0143, 0x0143]
PUSH2 0x001d    //[0x001d, 0x0143, 0x0143]
PUSH0           //[0x00, 0x001d, 0x0143, 0x0143]
CODECOPY        //[0x0143]
PUSH0           //[0x00, 0x0143]
RETURN          //[]
INVALID         //[]

//2 RUNTIME CODE
//c Entry Point for all calls
//c free memory pointer
PUSH1 0x80
PUSH1 0x40
MSTORE

//c msg.value check
CALLVALUE      //[msg.value]
DUP1           //[msg.value, msg.value]
ISZERO         //[0x01, msg.value]
PUSH2 0x000f   //[0x000f, 0x01, msg.value]
JUMPI          //[msg.value]
PUSH0          //[0x00, msg.value]
DUP1           //[0x00, 0x00, msg.value]
REVERT         //[msg.value]

//c this jumpdest below has the 0x000f program counter and you can see this in evm.codes by pasting the bytecode in the playground as usual

//c function selector size check
JUMPDEST     //[msg.value]
POP          //[]
PUSH1 0x04   //[0x04]
CALLDATASIZE  //[bytesizeofcalldata, 0x04]
LT            //[1 if bytesizeofcalldata < 4 else 0]
PUSH2 0x0034  //[0x0034, 1 if bytesizeofcalldata < 4 else 0]
JUMPI         //[]

//c solidity function dispatcher for updateHorseNumber
PUSH0         //[0x00]
CALLDATALOAD  //[calldata]
PUSH1 0xe0    //[224, calldata]
SHR           //[calldatafunction_selector]
DUP1          //[calldatafunction_selector, calldatafunction_selector]
PUSH4 0xcdfead2e //[0xcdfead2e, calldatafunction_selector, calldatafunction_selector]
EQ             //[1 if calldatafunction_selector == 0xcdfead2e else 0, calldatafunction_selector]
PUSH2 0x0038   //[0x0038, 1 if calldatafunction_selector == 0xcdfead2e else 0, calldatafunction_selector]
JUMPI           //[calldatafunction_selector]


//c solidity function dispatcher for readNumberOfHorses
DUP1            //[calldatafunction_selector, calldatafunction_selector]
PUSH4 0xe026c017  //[0xe026c017, calldatafunction_selector, calldatafunction_selector]
EQ          //[1 if calldatafunction_selector == 0xe026c017 else 0, calldatafunction_selector]
PUSH2 0x0054   //[0x0054, 1 if calldatafunction_selector == 0xe026c017 else 0, calldatafunction_selector]
JUMPI        //[calldatafunction_selector]

//c revert jumpdest
JUMPDEST
PUSH0
DUP1
REVERT

//c solidity function JUMPDEST 1 for updateHorseNumber. This is the 0x0038 jumpdest
JUMPDEST    //[calldatafunction_selector]
PUSH2 0x0052  //[0x0052, calldatafunction_selector]
PUSH1 0x04    //[0x04, 0x0052, calldatafunction_selector]
DUP1           //[0x04, 0x04, 0x0052, calldatafunction_selector]
CALLDATASIZE   //[bytesizeofcalldata, 0x04, 0x04, 0x0052, calldatafunction_selector]
SUB            //[bytesizeofcalldata - 4, 0x04, 0x0052, calldatafunction_selector]
DUP2           //[0x04, bytesizeofcalldata - 4, 0x04, 0x0052, calldatafunction_selector]
ADD           //[bytesizeofcalldata, 0x04, 0x0052, calldatafunction_selector]
SWAP1         //[0x04, bytesizeofcalldata, 0x0052, calldatafunction_selector]
PUSH2 0x004d  //[0x004d, 0x04, bytesizeofcalldata, 0x0052, calldatafunction_selector]
SWAP2         //[bytesizeofcalldata, 0x04, 0x004d, 0x0052, calldatafunction_selector]
SWAP1         //[0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x00ba  //[0x00ba, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMP          //[0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]


//c solidity function JUMPDEST 11 for updateHorseNumber. this is the 0x004d jumpdest
JUMPDEST //[calldatawithoutselector, 0x0052, calldatafunction_selector]
PUSH2 0x0072 //[0x0072, calldatawithoutselector, 0x0052, calldatafunction_selector]
JUMP    //[calldatawithoutselector, 0x0052, calldatafunction_selector]

//c solidity function JUMPDEST 13 for updateHorseNumber. this is the 0x0052 jumpdest
JUMPDEST //[calldatawithoutselector, calldatafunction_selector]
STOP // execution ends here for updateHorseNumber

//c solidity function JUMPDEST 1 for readNumberOfHorses. this is the 0x0054 jumpdest
JUMPDEST  //[calldatafunction_selector]
PUSH2 0x005c  //[0x005c, calldatafunction_selector]
PUSH2 0x007b  //[0x007b, 0x005c, calldatafunction_selector]
JUMP  //[0x005c, calldatafunction_selector]

//c solidity function JUMPDEST 3 for readNumberOfHorses. this is the 0x005c jumpdest
JUMPDEST //[valueinslot0, calldatafunction_selector]
PUSH1 0x40 //[0x40, valueinslot0, calldatafunction_selector]
MLOAD  //[0x80,valueinslot0, calldatafunction_selector]
PUSH2 0x0069  //[0x0069, 0x80, valueinslot0, calldatafunction_selector]
SWAP2   //[valueinslot0, 0x80, 0x0069, calldatafunction_selector]
SWAP1   //[0x80, valueinslot0, 0x0069, calldatafunction_selector]
PUSH2 0x00f4 //[0x00f4, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
JUMP //[0x80, valueinslot0, 0x0069, calldatafunction_selector]

//c solidity function JUMPDEST 9 for readNumberOfHorses. this is the 0x0069 jumpdest
JUMPDEST //[0xa0, calldatafunction_selector]
PUSH1 0x40  //[0x40, 0xa0, calldatafunction_selector]
MLOAD    //[0x80, 0xa0, calldatafunction_selector]
DUP1  //[0x80, 0x80, 0xa0, calldatafunction_selector]
SWAP2 //[0xa0, 0x80, 0x80, calldatafunction_selector]
SUB   //[0x20, 0x80, calldatafunction_selector]
SWAP1  //[0x80, 0x20, calldatafunction_selector]
RETURN  //[calldatafunction_selector]

//c solidity function JUMPDEST 12 for updateHorseNumber. this is the 0x0072 jumpdest
JUMPDEST //[calldatawithoutselector, 0x0052, calldatafunction_selector]
DUP1  //[calldatawithoutselector, calldatawithoutselector, 0x0052, calldatafunction_selector]
PUSH0  //[0x00, calldatawithoutselector, calldatawithoutselector, 0x0052, calldatafunction_selector]
DUP2  //[calldatawithoutselector, 0x00, calldatawithoutselector, calldatawithoutselector, 0x0052, calldatafunction_selector]
SWAP1  //[0x00, calldatawithoutselector, calldatawithoutselector, calldatawithoutselector, 0x0052, calldatafunction_selector]
SSTORE  //[calldatawithoutselector,calldatawithoutselector, 0x0052, calldatafunction_selector]
POP  //[calldatawithoutselector, 0x0052, calldatafunction_selector]
POP  //[0x0052, calldatafunction_selector]
JUMP //[calldatafunction_selector]

//c solidity function JUMPDEST 2 for readNumberOfHorses. this is the 0x007b jumpdest
JUMPDEST //[0x005c, calldatafunction_selector]
PUSH0   //[0x00, 0x005c, calldatafunction_selector]
DUP1    //[0x00, 0x00, 0x005c, calldatafunction_selector]
SLOAD   //[valueinslot0, 0x00, 0x005c, calldatafunction_selector]
SWAP1   //[0x00, valueinslot0, 0x005c, calldatafunction_selector]
POP     //[valueinslot0, 0x005c, calldatafunction_selector]
SWAP1   //[0x005c, valueinslot0, calldatafunction_selector]
JUMP    //[valueinslot0, calldatafunction_selector]

//c this is the revert jumpdest for the calldata size check. this is the 0083 jumpdest. when the calldata size after function selector is less than 32 bytes, this is the jumpdest that hits
JUMPDEST
PUSH0
DUP1
REVERT

//c solidity function JUMPDEST 6 for updateHorseNumber. this is the 0x0087 jumpdest
JUMPDEST //[calldatawithoutselector, 0x0099, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH0 //[0x00, calldatawithoutselector, 0x0099, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP2 //[calldatawithoutselector, 0x00, calldatawithoutselector, 0x0099, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SWAP1 //[0x00, calldatawithoutselector, calldatawithoutselector, 0x0099, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
POP //[calldatawithoutselector, calldatawithoutselector, 0x0099, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SWAP2  //[0x0099, calldatawithoutselector, calldatawithoutselector, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SWAP1 //[calldatawithoutselector, 0x0099, calldatawithoutselector, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
POP  //[0x0099, calldatawithoutselector, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMP   //[calldatawithoutselector, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]


//c solidity function JUMPDEST 5 for updateHorseNumber. this is the 0x0090 jumpdest
JUMPDEST  //[calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x0099  //[0x0099, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP2  // [calldatawithoutselector, 0x0099, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x0087 //[0x0087,calldatawithoutselector, 0x0099, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMP //[calldatawithoutselector, 0x0099, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]


//c solidity function JUMPDEST 7 for updateHorseNumber. this is the 0x0099 jumpdest
JUMPDEST //[calldatawithoutselector, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP2 //[calldatawithoutselector, calldatawithoutselector, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
EQ   //[1, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x00a3  //[0x00a3, 1, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMPI  //[calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]


PUSH0
DUP1
REVERT

//c solidity function JUMPDEST 8 for updateHorseNumber. this is the 0x00a3 jumpdest
JUMPDEST //[calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
POP //[0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMP //[calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]

//c solidity function JUMPDEST 4 for updateHorseNumber. this is the 0x00a6 jumpdest
JUMPDEST //[0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH0   //[0x00, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP2  //[0x04,0x00, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
CALLDATALOAD  //[calldatawithoutselector,0x00, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SWAP1  //[0x00,calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
POP    //[calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x00b4 //[0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP2    //[calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x0090  //[0x0090, calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMP    //[calldatawithoutselector, 0x00b4, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]

//c solidity function JUMPDEST 9 for updateHorseNumber. this is the 0x00b4 jumpdest
JUMPDEST //[calldatawithoutselector, 0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SWAP3   //[0x00dc, 0x04, bytesizeofcalldata, calldatawithoutselector, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SWAP2  //[bytesizeofcalldata, 0x04, 0x00dc, calldatawithoutselector, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
POP  //[0x04, 0x00dc, calldatawithoutselector, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
POP  //[0x00dc, calldatawithoutselector, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMP  //[calldatawithoutselector, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]

//c solidity function JUMPDEST 2 for updateHorseNumber. this is the 0x00ba jumpdest
JUMPDEST    //[0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH0       //[0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH1 0x20  //[0x20, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP3       //[0x04, 0x20, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP5       //[bytesizeofcalldata, 0x04, 0x20, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SUB        //[bytesizeofcalldata - 4, 0x20, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SLT       //[1 if bytesizeofcalldata - 4 < 32 else 0, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
ISZERO    //[1 if SLT opcode result is 0 else 0, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x00cf   //[0x00cf, 1 if SLT opcode result is 0 else 0, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMPI  //[0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]

//c if the JUMPI does nothing, it means that in the calldata, after the function selector, there isnt up to 32 bytes which is the size of a uint256. so the function will revert with the following 3 opcodes. this jumps to 0x0083 which i have identified as a jumpdest that has a revert in its flow
PUSH2 0x00ce  //[0x00ce, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x0083  //[0x0083, 0x00ce, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMP         //[0x00ce, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]


JUMPDEST

//c solidity function JUMPDEST 3 for updateHorseNumber. this is the 0x00cf jumpdest
JUMPDEST     //[0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH0       //[0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x00dc   //[0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP5      //[bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP3      //[0x00, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
DUP6      //[0x04, 0x00, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
ADD       //[0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
PUSH2 0x00a6 //[0x00a6, 0x04, bytesizeofcalldata, 0x00dc, 0x00,0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
JUMP //[0x04, bytesizeofcalldata, 0x00dc, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]

//c solidity function JUMPDEST 10 for updateHorseNumber. this is the 0x00dc jumpdest
JUMPDEST //[calldatawithoutselector, 0x00, 0x00, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SWAP2 //[0x00, 0x00, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
POP   //[0x00, calldatawithoutselector, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
POP   //[calldatawithoutselector, 0x04, bytesizeofcalldata, 0x004d, 0x0052, calldatafunction_selector]
SWAP3  //[0x004d, 0x04, bytesizeofcalldata, calldatawithoutselector, 0x0052, calldatafunction_selector]
SWAP2  //[bytesizeofcalldata, 0x04, 0x004d, calldatawithoutselector, 0x0052, calldatafunction_selector]
POP   //[0x04, 0x004d, calldatawithoutselector, 0x0052, calldatafunction_selector]
POP   //[0x004d, calldatawithoutselector, 0x0052, calldatafunction_selector]
JUMP  //[calldatawithoutselector, 0x0052, calldatafunction_selector]

//c solidity function JUMPDEST 5 for readNumberOfHorses. this is the 0x00e5 jumpdest
JUMPDEST  //[valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
PUSH2 0x00ee  //[0x00ee, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
DUP2   //[valueinslot0, 0x00ee, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
PUSH2 0x0087  //[0x0087, valueinslot0, 0x00ee, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
JUMP   //[valueinslot0, 0x00ee, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]

//c solidity function JUMPDEST 6 for readNumberOfHorses. this is the 0x0087 jumpdest
JUMPDEST //[valueinslot0, 0x00ee, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
PUSH0 //[0x00,valueinslot0, 0x00ee, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
DUP2 //[valueinslot0, 0x00,valueinslot0, 0x00ee, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
SWAP1 //[0x00, valueinslot0, valueinslot0, 0x00ee, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
POP //[valueinslot0, valueinslot0, 0x00ee, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
SWAP2  //[0x00ee, valueinslot0, valueinslot0, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
SWAP1 //[valueinslot0, 0x00ee, valueinslot0, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
POP  //[0x00ee, valueinslot0, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
JUMP   //[valueinslot0, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]


//c solidity function JUMPDEST 7 for readNumberOfHorses. this is the 0x00ee jumpdest
JUMPDEST //[valueinslot0, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
DUP3 //[0x80,valueinslot0, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
MSTORE  //[valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
POP //[0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
POP  //[0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
JUMP  //[0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]

//c solidity function JUMPDEST 4 for readNumberOfHorses. this is the 0x00f4 jumpdest
JUMPDEST //[0x80, valueinslot0, 0x0069, calldatafunction_selector]
PUSH0    //[0x00, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
PUSH1 0x20 //[0x20, 0x00, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
DUP3  //[0x80, 0x20, 0x00, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
ADD   //[0xa0, 0x00, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
SWAP1  //[0x00, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
POP  //[0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
PUSH2 0x0107  //[0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
PUSH0 //[0x00, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
DUP4 //[0x80,0x00, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
ADD  //[0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
DUP5  //[valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
PUSH2 0x00e5 //[0x00e5, valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
JUMP //[valueinslot0, 0x80, 0x0107, 0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]


//c solidity function JUMPDEST 8 for readNumberOfHorses. this is the 0x0107 jumpdest
JUMPDEST //[0xa0, 0x80, valueinslot0, 0x0069, calldatafunction_selector]
SWAP3  //[0x0069, 0x80, valueinslot0, 0xa0, calldatafunction_selector]
SWAP2  //[valueinslot0, 0x80, 0x0069, 0xa0, calldatafunction_selector]
POP    //[0x80, 0x0069, 0xa0, calldatafunction_selector]
POP   //[0x0069, 0xa0, calldatafunction_selector]
JUMP  //[0xa0, calldatafunction_selector]

//c METADATA
INVALID
LOG2
PUSH5 0x6970667358
INVALID
SLT
KECCAK256
PUSH7 0x47c0641c72fe75
INVALID
PUSH28 0x11ec4b7112cf778846472076e40974f4f03482b6aab064736f6c6343
STOP
ADDMOD
EQ
STOP
CALLER