// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{   

    Super::BeginPlay();
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);

    Isograms =GetValidWords(Words);
    
    SetupGame();
   
    
}

void UBullCowCartridge::OnInput(const FString & PlayerInput) // When the player hits enter
{

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
        //  PrintLine(Input);
    }
    else //Checking PlayerGuess
    {
        ProcessGuess(PlayerInput);
    }
}

void UBullCowCartridge::SetupGame()
{
    //wellcome player
    PrintLine(TEXT("Hi Wellcome to Bull Cows Game"));

    HiddenWord = Isograms[FMath::RandRange(0,Isograms.Num()-1)];
    Lives = HiddenWord.Len()*2;
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and \nPress enter to contnie....")); // prompt player for guess
    
    //PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);
   

}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;

    PrintLine(TEXT("\nPress enter to play again."));
}

void UBullCowCartridge::ProcessGuess(const FString & Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have Won!"));
        EndGame();
        return;
    }
  
    if (Guess.Len() != HiddenWord.Len())
    {   
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try guessing again!\nYou have %i lives remaining."), Lives);

        return;
    }
    // check if isogram

    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess agian"));
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
    
    FBullCowCount Score =  GetBullCows(Guess);

    PrintLine(TEXT("You have %i Bulls and %i Cows"),Score.Bulls,Score.Cows);

    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);


}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{

        for(int32 Index = 0; Index<Word.Len();Index++){

            for(int32 Comparison = Index+1; Comparison < Word.Len();Comparison++){

                if (Word[Index]==Word[Comparison])
                {
                    return false;
                }               

            }
        }

   return true;
 
    
}

TArray<FString>UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{

 TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        // PrintLine(TEXT("%s"),*Words[Index]);
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {   

            ValidWords.Emplace(Word);
         
        }
        
    }
    return ValidWords;
}


 FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
 {
    FBullCowCount Count;
 
     for(int32 GuessIndex = 0; GuessIndex< Guess.Len();GuessIndex++)
     {
         if (Guess[GuessIndex]==HiddenWord[GuessIndex])
         {
             Count.Bulls++;
             continue;
         }
         for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
         {
            if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
            {
               Count.Cows++;
               break;
            }
            
         }
         
         
     }
     return Count;
 }   
