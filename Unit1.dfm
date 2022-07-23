object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = '   1. '#1055#1088#1080#1085#1094#1080#1087' '#1089#1074#1086#1073#1086#1076#1085#1086#1075#1086' '#1074#1099#1073#1086#1088#1072
  ClientHeight = 574
  ClientWidth = 822
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 11
    Top = 32
    Width = 800
    Height = 500
  end
  object Label1: TLabel
    Left = 11
    Top = 8
    Width = 128
    Height = 14
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1077#1076#1080#1085#1080#1094': 0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 691
    Top = 8
    Width = 120
    Height = 14
    Alignment = taRightJustify
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1085#1091#1083#1077#1081': 0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 608
    Top = 545
    Width = 203
    Height = 14
    Alignment = taRightJustify
    Caption = #1057#1086#1086#1090#1085#1086#1096#1077#1085#1080#1077' '#1077#1076#1080#1085#1080#1094' '#1080' '#1085#1091#1083#1077#1081': -'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clOlive
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 11
    Top = 541
    Width = 250
    Height = 25
    Caption = #1057#1086#1074#1077#1088#1096#1080#1090#1100' 1,600,000 '#1089#1074#1086#1073#1086#1076#1085#1099#1093' '#1074#1099#1073#1086#1088#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
end
