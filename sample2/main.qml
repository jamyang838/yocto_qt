import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
//import QtQuick.VirtualKeyboard 2.4

Window {
    id: window
    visible: true
    width: 640
    height: 480
    color: "red"
    title: qsTr("Hello World")

    Column{
        Button{
            text: "asd"
            width: 200
            padding: 5
            height: 50
        }

        Image {
            source: "/home/yang/Pictures/a.jpg"
            width: 400
            height: 200
        }

        Text {

            text: qsTr("text")
        }


    }

/*
    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
    */
}

