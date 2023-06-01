#include "progress.h"

Progress::Progress(MyText* progress_, Picture* button_, MyRectangle* back_) {
   progress = progress_;
   button = button_;
   back = back_;
}

MyText* Progress::getProgress() {
    return progress;
}

Picture* Progress::getButton() {
    return button;
}

MyRectangle* Progress::getBack() {
    return back;
}

void Progress::setDna(int dna_) {
    progress->setText(QString::number(dna_));
}
