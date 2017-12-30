/*
Grid is always square of size n*n, n=1,3,5,7,9...
Grid size is sqrt input rounded up to closest odd number
Square 1 has coordinates (0,0), spiraling outwards

5   4   3
6   1   2
7   8   9

(-1,1)   (0,1)   (1,1)
(-1,0)   (0,0)   (1,0)
(-1,-1)  (0,-1) (1,-1)
*/

let isEven = (number: int) : bool => {
  switch (number mod 2) {
    | 0 => true;
    | _ => false;
  };
};

let gridSize = (square: int) : int=> {
  switch (square < 2) {
    | true => 1;
    | false => {
      let roundedSize = Js.Math.ceil(sqrt(float_of_int(square)));
      switch (isEven(roundedSize)) {
        | true => roundedSize + 1;
        | false => roundedSize;
      };
    };
  };
};

let getWhichSide = (square: int) => {
  let gridSize = gridSize(square);
  let maxPoint = gridSize*gridSize;
  let sideDifference = gridSize - 1;

  /* Jahapp, hur gör man det här snyggt? 😓*/
  if (square >= maxPoint - sideDifference) {
    /* BOTTOM ROW */
    0;
  } else if (square >= maxPoint - 2*sideDifference) {
    /* LEFT COL */
    1;
  } else if (square >= maxPoint - 3*sideDifference) {
    /* TOP ROW */
    2;
  } else {
    /* RIGHT COL */
    3;
  };
};

let getCoordinates = (square: int) : (int, int) => {
  let gridSize = gridSize(square);
  let gridNumber = (gridSize - 1) / 2;
  let maxPoint = gridSize*gridSize;
  let sideDifference = gridSize - 1;

  if (gridSize < 2) {
    (0,0);
  } else {
    switch (getWhichSide(square)) {
      | 0 => (square - (maxPoint - sideDifference) - gridNumber, -gridNumber);
      | 1 => (-gridNumber, maxPoint - 2 * sideDifference + gridNumber - square);
      | 2 => (maxPoint - 3 * sideDifference + gridNumber - square, gridNumber);
      | _ => (gridNumber, square + gridNumber - (maxPoint - 3 * sideDifference));
    };
  };
};

let manhattanDistToCenter = (x:int, y:int) : int => {
  abs(x) + abs(y);
};

let calcDistance = (square: int) : int => {
  let (x,y) = getCoordinates(square);
  manhattanDistToCenter(x,y);
};

let run = () => {
  let manhattanDist = calcDistance(265149);
  Js.log(manhattanDist);
};

/*run();*/

