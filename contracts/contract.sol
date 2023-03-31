// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.6.8;

contract getDetails {
    struct Person {
        // State variables
        int aadharNo;
        string name;
        int mobileNo;
        string registration;
        string insurance;
        string emission;
    }

    Person[] persons;

    function addPerson(
        int aadharNo,
        string memory name,
        int mobileNo,
        string memory registration,
        string memory insurance,
        string memory emission
    ) public {
        Person memory f = Person(
            aadharNo,
            name,
            mobileNo,
            registration,
            insurance,
            emission
        );

        persons.push(f);
    }

    function getdetails(
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

        for (i = 0; i < persons.length; i++) {
            Person memory f = persons[i];

            if (f.aadharNo == aadharNo) {
                return (
                    f.name,
                    f.mobileNo,
                    f.registration,
                    f.insurance,
                    f.emission
                );
            }
        }

        return ("Not Found", -1, "Not Found", "Not Found", "Not Found");
    }

    function getstatus(int aadharNo) public view returns (string memory) {
        uint i;

        for (i = 0; i < persons.length; i++) {
            Person memory f = persons[i];

            if (f.aadharNo == aadharNo) {
                return (f.emission);
            }
        }
        return ("Please enter correct aadhar no. !");
    }
}