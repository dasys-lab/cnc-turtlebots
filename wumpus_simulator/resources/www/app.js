//---------------------GLOBAL_VARIABLES---------------------
var fieldSize = 0;
var traps = 0;
var wumpus = 0;


//---------------------ENTRY_POINT---------------------
$(document).ready(function() {

    //Activate materialize elements
    $('.dropdown-button').dropdown();
    $('.modal').modal();

    //Listen on click of the random button from the settings modal, to create some values
    $('#randomValuesBtn').click(function() {

        //Calculate the field size, number of traps and wumpus randomly
        fieldSize = Math.floor((Math.random() * 12) + 4); //Adjust the % value to the the upper bounce
        traps = Math.floor((Math.random() * (Math.pow(fieldSize, 2) / 4)) + 1);
        wumpus = Math.floor((Math.random() * fieldSize) + 1);

        //Set the random values
        $('#playgroundSize').val(fieldSize);
        $('#trapNumbers').val(traps);
        $('#wumpusNumbers').val(wumpus);
        $('#arrowAgent').prop('checked', (fieldSize % 2 === 0));

        //Update the text fields
        Materialize.updateTextFields();

    });

    //Listen on the close button from the settings modal
    $('#settingsCancel').click(function() {

        //Remove the last entry from the settings modal
        $('#playgroundSize').val('');
        $('#trapNumbers').val('');
        $('#wumpusNumbers').val('');
        $('#arrowAgent').prop('checked', false);
        Materialize.updateTextFields();

        //Just close the modal
        $('#newWorldModal').modal('close');

    });


    //Listen on the ok button from the settings modal
    $('#settingsOk').click(function() {

        //Check if there are all needed values
        if($('#playgroundSize').val() && $('#trapNumbers').val() && $('#wumpusNumbers').val()) {

            //Set the labels from the info bar
            $('#arrow').text('Arrow: ' + (fieldSize % 2 === 0));
            $('#wumpus').text('Wumpus: ' + wumpus);
            $('#traps').text('Traps: ' + traps);
            $('#size').text('Size: ' + fieldSize);

            //Remove the last entry from the settings modal
            $('#playgroundSize').val('');
            $('#trapNumbers').val('');
            $('#wumpusNumbers').val('');
            $('#arrowAgent').prop('checked', false);
            Materialize.updateTextFields();

            //Draw the playground
            drawPlayground();

            //Close the modal
            $('#newWorldModal').modal('close');

        }
    });
});


//---------------------METHODS---------------------
//Draws the playground, just a grid depending on the field size
function drawPlayground() {

    //Get the table as root
    var root = $('#board');

    //Clear the board
    root.empty();

    //Create html grid content
    var grid = '';

    for(var i = 0; i < fieldSize; i++) {

        //Append a row
        grid += '<div style="line-height: 1px;">';

        for(var j = 0; j < fieldSize; j++) {

            //Append a new cell to the last row, the size of a single cell is set in the ground css class in the style.css
            grid += '<div class="ground"></div>';

        }

        //Close the row div
        grid += '</div>'

    }

    //Add the grid to the board
    root.html(grid);

}

