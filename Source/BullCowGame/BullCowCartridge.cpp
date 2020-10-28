// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s. \nIt is %i Characters long"), *HiddenWord, HiddenWord.Len()); // Debug Line
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    // int32 a = 1;
    // int32 b=  ++a; // 2
    // int32 c = ++ ++a; //don not do this
    // int32 d = a +=2;
    // int32 e = a++;
    // PrintLine(TEXT("%i , %i, %i, %i, %i"),a,b,c,d,e);
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
        //  PrintLine(Input);
    }
    else //Checking PlayerGuess
    {
        ProcessGuess(Input);

   
    }

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
    PrintLine(TEXT("Hi Wellcome to Bull Cows Game"));
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and \nPress enter to contnie....")); // prompt player for guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}

void UBullCowCartridge::ProcessGuess()
{
         if (Input == HiddenWord)
        {
            PrintLine(TEXT("You have Won!"));
            EndGame();
        }
        else
        {
            
            PrintLine(TEXT("You lost live"));
            PrintLine(TEXT("%i"),--Lives);
            if (Lives > 0)
            {

                if (Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry, try guessing again!\nYou have %i lives remaining."), Lives);
                }
                
            }
            else
                {

                    PrintLine(TEXT("You have no lives left!"));
                    EndGame();
                }
        }
}