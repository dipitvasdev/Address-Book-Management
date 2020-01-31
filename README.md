# Address-Book-Management
This project entitled Address Book Management System is a contact management  system. It is based on the concept of Object Oriented Programing and use of
Binary File.Object oriented programing ensure no one can alter the data easily and also helps encapsulate the data while maintaining simplicity.This program is able to achieve the same through OOP. This Program can serve a useful purpose by keeping all the necessary details a safe place. The Program can do the following functions:-

Add Member: This function can add a member to the records stored in binary file. It automatically assigns member number to a new member by incrementing the previous member number.
Show Member: This member is used to display list of all members stored in binary file.
Delete Member: This member can delete a particular member from the binary file. It works by transferring all the record except for the one which is to be deleted from original file to a temporary file. It then transfers the content back from temporary file to original file.
Modify Member: This function can modify particular and important details of a member i.e. email,address,city and country.The program works by re inputting the data to be modified.
Clear Data: This function is used to clear all the data from binary file. It works on the simple logic that when a binary file is opened in ‘out’ mode , the content originally stored in file is overwritten. 
Search Content : The program allows the user or the admin to search for members from the binary file. It works on the logic of linear search in an array. It can search for content on the basis of:-
Member No: It helps the user to search for a specific member number from the record.
Member Name: It helps the user to search for a specific member name from the record.It is case-insensitive.
Member Email ID: It helps the user to search for a specific Email ID  from the record.It is case-insensitive.
Member Mobile Number: It helps the user to search for a mobile number belonging to a member from the record.
Member City: It helps the user to search for a specific residential city of respective member from the record.It is case-insensitive.
Member Country: It helps the user to search for a specific residential country of respective member from the record.It is case-insensitive.
The program also contains separate menu functions for the admin who can manage the data in the record and a search menu to search for members.
