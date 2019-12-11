-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Počítač: 127.0.0.1
-- Vytvořeno: Stř 11. pro 2019, 21:13
-- Verze serveru: 10.4.10-MariaDB
-- Verze PHP: 7.3.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Databáze: `fingerprint`
--

-- --------------------------------------------------------

--
-- Struktura tabulky `data`
--

CREATE TABLE `data` (
  `id` int(5) NOT NULL,
  `name` text COLLATE utf8_czech_ci NOT NULL,
  `date` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_czech_ci;

--
-- Vypisuji data pro tabulku `data`
--

INSERT INTO `data` (`id`, `name`, `date`) VALUES
(0, 'Kadlec Ondrej', '2019-12-11 16:26:26'),
(1, 'Kadlec Ondrej', '2019-12-11 16:26:51'),
(2, 'Kadlec Ondrej', '2019-12-11 16:27:45');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
