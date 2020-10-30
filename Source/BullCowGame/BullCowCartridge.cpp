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

    PrintLine(TEXT("\nPress enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have Won!"));
        EndGame();
        return;
    }
    // if game is over then clear the Screen and SetupGame() the game
    // else checking the player guess

    // check if isogram

    // if(!IsIsogram){
    //     PrintLine(TEXT("No repeating letters, guess agian"));
    // }

  
    if (Guess.Len() != HiddenWord.Len())
    {   
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try guessing again!\nYou have %i lives remaining."), Lives);

        return;
    }
    //remove lift
    PrintLine(TEXT("You lost live"));
    --Lives;

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }

    //show player bulls and cows
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);

    //check Right
    // Remove Life

    // Check if lives > 0
    // If yes guess again
    // show new lefts
    // if no show game over adn HiddenWord?
   
    // play agin or quit
}