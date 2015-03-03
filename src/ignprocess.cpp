#include "ignprocess.h"

ignprocess::ignprocess(QObject *parent) :
    QObject(parent)
{

}

void ignprocess::exec(const QString &cli){
    //proc = new QProcess( this );
    proc.setReadChannelMode(QProcess::MergedChannels);
    connect( &proc, SIGNAL(readyReadStandardOutput()), this, SLOT( _out()) );
    proc.start(cli);
}

void ignprocess::_out(){
    emit this->out(proc.readAllStandardOutput());
}

void ignprocess::kill(){
    this->proc.kill();
}

int ignprocess::pid(){
    return this->proc.pid();
}
