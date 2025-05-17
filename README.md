# ☕ Projet Cafetière Automatique

Ce projet vise à concevoir un **système de contrôle intelligent pour une cafetière automatique** en utilisant un microcontrôleur **STM32F401VE**. Il permet à l’utilisateur de sélectionner un type de café, de lancer automatiquement le processus de brassage, de surveiller la température, de gérer les niveaux de stock et de sauvegarder les seuils critiques dans une mémoire EEPROM.

## 🎯 Objectifs

- Offrir une interface simple et intuitive pour choisir entre différents types de cafés.
- Assurer un brassage automatisé avec retour visuel et sonore.
- Implémenter la surveillance de température et la gestion des stocks.
- Utiliser l'EEPROM pour stocker des seuils personnalisables.

## 🧰 Matériel utilisé

- Microcontrôleur STM32F401VE
- Écran LCD
- Boutons-poussoirs (Sélection, Validation, Seuils, Maintenance)
- Moteurs CC (mécanisme de disque + ventilation)
- Capteur de température
- Capteurs de niveau (café et lait)
- Potentiomètres (simulateurs de seuils)
- LED (verte et rouge)
- Buzzer
- EEPROM

## ⚙️ Fonctionnalités

### 🔘 État d'attente
- LED verte clignote
- LCD affiche “Choisir Café”
- Attente de l'action de l'utilisateur

### 🧃 Choix du Café
- Boutons : "Expresso" ou "Café au lait"
- Bouton "Valider" doit être pressé dans les 10s (Timer)

### 🔄 Brassage automatique
- Activation d’un moteur pour simuler un disque de brassage
- Affichage de l’état de progression

### 🌡️ Surveillance Température
- Capteur analogique
- Refroidissement activé automatiquement en cas de surchauffe

### 📉 Réapprovisionnement automatique
- Capteurs de niveau (café/lait) (répresentés par des potentiomètre en isis)
- Si seuil atteint : LED rouge + buzzer + désactivation interface

### 🧠 Sauvegarde des seuils
- Bouton "Seuils" active le réglage via potentiomètres
- Seuils stockés dans l’EEPROM après 10 secondes


## 🛠️ Compilation & Simulation

- **Environnement de développement** : STM32CubeMX, Keil uVision
- **Simulation** : ISIS/Proteus
- **Langage** : C (HAL)

## ✅ Travaux réalisés

- ✅ Étude architecture STM32F401VE
- ✅ Mapping des capteurs/actuateurs sur les broches
- ✅ Simulation complète (Proteus)
- ✅ Implémentation C : état d’attente, choix café, brassage, ADC, EEPROM
- ✅ Présentation + rapport final

## 📽️ Démo & Présentation

<video controls src="Enregistrement de l'écran 2025-05-17 020501.mp4" title="Title"></video>




