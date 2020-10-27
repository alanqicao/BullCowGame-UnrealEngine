// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
   
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s. \nIt is %i Characters long"),*HiddenWord,HiddenWord.Len());// Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    int32 a = 1;
    ++a;
    PrintLine(TEXT("%i"),a);
    // if (bGameOver)
    // {
    //      ClearScreen();
    //      SetupGame();
    //     //  PrintLine(Input);
    // }
    // else //Checking PlayerGuess
    // {
    //     if (Input==HiddenWord)
    // {
    //     PrintLine(TEXT("You have Won!"));
    //     EndGame();
    // }
    // else
    // {
    //     if(Input.Len()!= HiddenWord.Len()){

    //         PrintLine(TEXT("The Hidden Word is %i characters long, \nYou have lost!"),HiddenWord.Len());
    //         EndGame();
    //     }      
    // }
    // }
    
    
    // if game is over then clear the Screen and SetupGame() the game
    // else checking the player guess 
 

   
    
    // check if isogram
    // check right number of characters
    //remove lift
     //check Right
     // Remove Life

     // Check if lives > 0
     // If yes guess again 
     // show new lefts
     // if no show game over adn HiddenWord?
     // prompt play again, press enter to play again?
     // check user input
     // play agin or quit
}

void UBullCowCartridge::SetupGame()
{
     //wellcome player
    PrintLine (TEXT("Hi Wellcome to Bull Cows Game"));
    HiddenWord = TEXT("cakes"); 
    Lives = 4;
    bGameOver = false;
    PrintLine (TEXT("Guess the %i letter word!"),HiddenWord.Len()); 
    PrintLine(TEXT("Type in your guess.\nPress enter to contnie...."));// prompt player for guess  
}

void UBullCowCartridge::EndGame(){
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));

}