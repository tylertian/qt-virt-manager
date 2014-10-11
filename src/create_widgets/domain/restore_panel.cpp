#include "restore_panel.h"

RestorePanel::RestorePanel(QWidget *parent) :
    QWidget(parent)
{
    save = new QPushButton(QIcon::fromTheme("document-save"), "Save", this);
    save->setToolTip("Save current state");
    revert = new QPushButton(QIcon::fromTheme("document-revert"), "Revert", this);
    revert->setToolTip("Revert to previous state");
    restoreMenu = new DeviceRestoreMenu(this);
    restoreMenu->revertData->setEnabled(false);
    revert->setMenu(restoreMenu);
    panelLayout = new QHBoxLayout(this);
    panelLayout->addWidget(save);
    panelLayout->addWidget(revert);
    panelLayout->addStretch(-1);
    setLayout(panelLayout);
    connect(save, SIGNAL(clicked()),
            this, SIGNAL(saveData()));
    connect(restoreMenu->revertData, SIGNAL(triggered()),
            this, SIGNAL(revertData()));
    connect(restoreMenu->resetData, SIGNAL(triggered()),
            this, SIGNAL(resetData()));
}

/* public slots */
void RestorePanel::stateChanged()
{
    restoreMenu->revertData->setEnabled(true);
}
void RestorePanel::stateChanged(bool state)
{
    restoreMenu->revertData->setEnabled(state);
}
