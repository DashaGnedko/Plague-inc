#include "progress.h"

Progress::Progress(MyText* text_, MyText* progress_, Picture* picture_, Picture* button_, MyRectangle* back_, MyRectangle* progressBar_, MyRectangle* progressBarInfected_) {
   text = text_;
   progress = progress_;
   picture = picture_;
   button = button_;
   back = back_;
   progressBar = progressBar_;
   progressBarInfected = progressBarInfected_;
}

MyText* Progress::getText() {
    return text;
}

MyText* Progress::getProgress() {
    return progress;
}

Picture* Progress::getPicture() {
    return picture;
}

Picture* Progress::getButton() {
    return button;
}

MyRectangle* Progress::getBack() {
    return back;
}

MyRectangle* Progress::getProgressBar() {
    return progressBar;
}

MyRectangle* Progress::getProgressBarInfected() {
    return progressBarInfected;
}
