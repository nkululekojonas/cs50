<!--
 // tideman notes

 // Put more formally: 
    Step One: 
        Collect all voters' preferences into a matrix where preferences[i][j] represents the number of voters who prefer candidate i over candidate j. Compare all candidates in
        pairs, determine who wins each matchup, and calculate the margin of victory.

    Step Two: 
        Sort the candidate pairs by margin of victory in decreasing order, so that the strongest victories are considered first.

   Step Three: 
        Iterate through the sorted pairs and attempt to "lock" each pair into the graph. Before locking, check if adding the pair would create a cycle. If it would, skip that
        pair otherwise, lock it in.

        Starting with the biggest margin determine if the winner loses to any one thats already locked in, if they dont add then if they do skip them as they win by a less margin 
        and it would create a cycle.

   Step Four: 
        The source of the graph is the winner i.e the a winner that has been locked in that doesnt lose to anyon else.
->
