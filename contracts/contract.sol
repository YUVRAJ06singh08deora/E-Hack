// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.6.8;

contract getDetails {
    struct Farmer {
        // State variables
        int aadharNo;
        string name;
        int mobileNo;
        string crop;
        string produce;
        string status;
    }

    Farmer[] farmers;

    function addFarmer(
        int aadharNo,
        string memory name,
        int mobileNo,
        string memory crop,
        string memory produce,
        string memory status
    ) public {
        Farmer memory f = Farmer(
            aadharNo,
            name,
            mobileNo,
            crop,
            produce,
            status
        );

        farmers.push(f);
    }

    function getFarmer(
        int aadharNo
    )
        public
        view
        returns (
            string memory,
            int,
            string memory,
            string memory,
            string memory
        )
    {
        uint i;

        for (i = 0; i < farmers.length; i++) {
            Farmer memory f = farmers[i];

            if (f.aadharNo == aadharNo) {
                return (f.name, f.mobileNo, f.crop, f.produce, f.status);
            }
        }

        return ("Not Found", -1, "Not Found", "Not Found", "Not Found");
    }

    function getstatus(int aadharNo) public view returns (string memory) {
        uint i;

        for (i = 0; i < farmers.length; i++) {
            Farmer memory f = farmers[i];

            if (f.aadharNo == aadharNo) {
                return (f.status);
            }
        }
        return ("Please enter correct aadhar no. !");
    }
}
