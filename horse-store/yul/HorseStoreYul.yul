object "HorseStoreYul" {

    code{
        datacopy(0, dataoffset("runtime"), datasize("runtime"))
        return(0,datasize("runtime"))
    }

    object "runtime"{
        code{
            //c loads the function selector from the calldata
            switch selector()

            //c what to do if the function selector is the one for updateNumberOfHorses
            case 0xcdfead2e{
                storeNumber(decodeAsUint())
            }

            //c what to do if the function selector is readNumberofHorses
            case 0xe026c017{
               returnNumber(getNumber(0))
            }

            //c in case the function selector gotten from the calldata is none of these
            default{
                revert(0,0)
            }

            //c helper functions
            function selector() ->s{
                s := div(calldataload(0), 0x100000000000000000000000000000000000000000000000000000000)
            }

            function storeNumber(n){
                sstore(0,n)
            }

            function getNumber(n) -> storedNumber{
               storedNumber:= sload(n)
            }

            function returnNumber(n){
                mstore(0, n)
                return(0, 0x20)
            }

            function decodeAsUint() -> v {
                let positionincalldata := 0x04
                if lt(calldatasize(), add(positionincalldata,0x20)){
                    revert(0,0)
                }
                v := calldataload(positionincalldata)
            }

        }
    }
}