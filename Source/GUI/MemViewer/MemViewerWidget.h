#pragma once

#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "MemViewer.h"

class MemViewerWidget : public QWidget
{
  Q_OBJECT

public:
  MemViewerWidget(QWidget* parent, u32 consoleAddress);

  void onJumpToAddressTextChanged();
  void onGoToMEM1Start();
  void onGoToMEM2Start();
  QTimer* getUpdateTimer() const;
  void hookStatusChanged(bool hook);
  void goToAddress(u32 address);

signals:
  void mustUnhook();

private:
  QLineEdit* m_txtJumpAddress;
  QPushButton* m_btnGoToMEM1Start;
  QPushButton* m_btnGoToMEM2Start;
  QTimer* m_updateMemoryTimer;
  MemViewer* m_memViewer;
};